// nsinfo.java
// M. J. Stemen
// 202401170920 MJS
// A program to interact with DNS
// note: uses dns_message class

import java.net.*;
import java.io.*;
import java.util.regex.*;

public class nsinfo
{
   public static void main(String[] args)
   {
      DatagramSocket dgsock;
      DatagramPacket request;
      DatagramPacket response;
	  // 208.67.222.222
//      byte[] name_server_ip = { (byte)208,(byte)67,(byte)222,(byte)222 };
      byte[] name_server_ip = { (byte)172,(byte)16,0,23 };
      byte[] request_buffer;
      byte[] response_buffer;


      try {

      if( args.length != 1 )
      {
         System.out.println( "USAGE:\r\n  java nsinfo <hostname>\r\n" +
                                       "  java nsinfo www.google.com\r\n" );
         System.exit(1);
      }

      response_buffer = new byte[ 1024 ];
      response = new DatagramPacket(response_buffer, response_buffer.length ); 

      dgsock = new DatagramSocket();
      request_buffer = new dns_message().getBytes( args[0] );
 
      System.out.println( new String(request_buffer) );

      request = 
        new DatagramPacket( request_buffer, request_buffer.length, InetAddress.getByAddress(name_server_ip), 53);
      

      dgsock.send( request );

      dgsock.receive( response );


      dns_message dns_response = new dns_message( response.getData() );

      String output = new String(response.getData() );
      Pattern p = Pattern.compile( "\\x0e" );
      Matcher m = p.matcher( output );

      //System.out.println( 
      //     m.replaceAll( "." ) );

           //URLEncoder.encode( output, "ISO-8859-1" ) );
			hexdump( response.getData(), response.getLength() );
      System.out.println( 
         Integer.toHexString( dns_response.id ) + "\n" +
         Integer.toHexString( dns_response.flags ) + "\n" +
         dns_response.qdcount + "\n" +
         dns_response.ancount + "\n" +
         dns_response.nscount + "\n" +
         dns_response.arcount + "\n" +
         "\n; Question(s)\n  " +
         dns_response.rdata.get( 0 ) 
         );
         for( int w = 0; 
            w < dns_response.ancount+dns_response.nscount+dns_response.arcount; w++ )
         {
            System.out.println(
               "; Answer\n  " +
               dns_response.rdata.get( w * 2 + 1 ) + "\n  " +
               dns_response.rdata.get( w * 2 + 2 ) 
            );
         } // end for

      }
      catch( Exception e)
      {
            System.out.println( "nsinfo.main: " + e +
            "\n(IndexOutOfBounds errors are often unhandled response types." +
            "\n i.e., unknown host name or SOA type.)");
            System.exit(1);
      }
      
   }
   
   public static void hexdump(byte[] data, int size) {
      int x;
	  int last = (size % 16);
      for(x=0; x < size; x++) {
	     System.out.printf( "%02X ", data[x] );
		 if( data[x]==0 | (data[x]>6 && data[x]<16) ) data[x] = 46;
		 if( (x+1) % 8 == 0 ) System.out.print( " " );
		 if( (x+1) % 16 == 0 ) System.out.println( new String(data,x-15,16));
	  }
	  for(int c=x; c < x + (16 - last); c++) {
	  System.out.print( "   " );
 	  if( (c+1) % 8 == 0 ) System.out.print( " " );
	  if( (c+1) % 16 == 0 ) System.out.println( new String(data,size-last,last));
	  }
	  
	  System.out.println();
   }
}
