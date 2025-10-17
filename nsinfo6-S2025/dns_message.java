// dns_message.java
// M. J. Stemen
// 202401170920 MJS
// A class representing DNS messages
// note: used with nsinfo class


import java.io.*;
import java.util.*;

public class dns_message
{
   public int id;
   public int flags;
   public int qdcount;
   public int ancount;
   public int nscount;
   public int arcount;
   public String host_name;
   public int qtype;
   public int qclass;
   public ArrayList<String> rdata;

   public dns_message()
   {
   }

   public dns_message( byte[] message )
   {
      DataInputStream data;
      StringBuffer hostname;
      int strlength;
      int record_type;
      int record_class;

      try {
         rdata = new ArrayList<String>();

         data = new DataInputStream( new ByteArrayInputStream( message ) );

         data.mark( 1000000 ); // mark beginning; mark expires after 1000000 bytes
         int bookmark = 0; // to remember where to return from mark
         boolean in_bookmark = false;

         this.id = data.readShort();
         this.flags = data.readShort();
         this.qdcount = data.readShort();
         this.ancount = data.readShort();
         this.nscount = data.readShort();
         this.arcount = data.readShort();

         bookmark = 12;

         // query section
         for( int w=0; w < this.qdcount; w++ )
         {
         hostname = new StringBuffer();

         strlength = (int)data.readByte();
         bookmark++;

         while( strlength != 0 )
         {
            byte[] buffer = new byte[ strlength ];
            data.readFully( buffer );
            if( !in_bookmark) bookmark+=strlength;
            hostname.append( new String(buffer) + "." );
            strlength = (int)data.readByte();
            if( !in_bookmark ) bookmark++;
         }

         hostname.append( " " + getQTYPE( (int)data.readShort() ) );
         hostname.append( " " + getQCLASS( (int)data.readShort() ) );

         bookmark+=4;

          rdata.add( "QD:" + hostname.toString() ); 

         }

         // answer section
         for( int w = 0; w < this.ancount + this.nscount + this.arcount; w++ )
         {
         hostname = new StringBuffer();

         strlength = (int)data.readUnsignedByte();
         bookmark++;

         while( strlength != 0 )
         {
            while( ( strlength & 0x00C0 ) == 192 ) // indicates compressed data
            {
               strlength = (strlength << 8) | (int)data.readUnsignedByte();
               strlength = strlength & 0x003fff;
               //System.out.println( "\nname.strlength=" + strlength );
               if( !in_bookmark) bookmark++;
               in_bookmark = true;

               data.reset();  // skip back to mark
               data.skipBytes( strlength );
               strlength = (int)data.readUnsignedByte();
            }
            
            byte[] buffer = new byte[ strlength ];
            data.readFully( buffer );
            if( !in_bookmark) bookmark+=strlength;
            hostname.append( new String(buffer) + "." );
            strlength = (int)data.readUnsignedByte();
            if( !in_bookmark) bookmark++;
         }

         if( in_bookmark) 
         {
         data.reset();
         data.skipBytes( bookmark ); // return to bookmark
         in_bookmark=false;
         }

         record_type = (int)data.readShort();
         record_class = (int)data.readShort();

         hostname.append( " " + getQTYPE( record_type ) );
         hostname.append( " " + getQCLASS( record_class ) );

		 int ttl = (int)data.readInt();
         hostname.append( " " + "TTL:" + ttl  );
		 
		 int rdlength = (int)data.readShort();
         hostname.append( " " + "RLEN:" + rdlength );

         bookmark += 10;

         rdata.add( "AN:" + hostname.toString() ); 

         // ********************************************
		 // MX = Mail Exchange Records
         // ********************************************
         if( record_type == 15) // MX record type
         {
         hostname = new StringBuffer();

		 hostname.append("(" + data.readUnsignedShort() + ") " );
		 bookmark += 2;
		 
		 
         strlength = (int)data.readUnsignedByte();
         bookmark++;

         while( strlength != 0 )
         {
            while( ( strlength & 0x00C0 ) == 192 ) // indicates compressed data
            {
               strlength = (strlength << 8 ) | (int)data.readUnsignedByte(); // offset from mark
               strlength = strlength & 0x003fff;
               //System.out.println( "\nansw.strlength=" + strlength );
               if( !in_bookmark) bookmark++;
               in_bookmark = true;

               data.reset();  // skip back to mark
               data.skipBytes( strlength );
               strlength = (int)data.readUnsignedByte();
            }
            byte[] buffer = new byte[ strlength ];
            data.readFully( buffer );
            if( !in_bookmark) bookmark+=strlength;
            hostname.append( new String(buffer) + "." );
            strlength = (int)data.readUnsignedByte();
            if( !in_bookmark) bookmark++;
         }

         if( in_bookmark) 
         {
         data.reset();
         data.skipBytes( bookmark ); // return to bookmark
         in_bookmark=false;
         }


         rdata.add( hostname.toString() ); 
         
         }
         // TYPE == CNAME, PTR, or NS
        else if( record_type == 5  || record_type == 12 || record_type == 2) 
         {
         // get RDATA for first answer TYPE=CNAME
         hostname = new StringBuffer();

         strlength = (int)data.readUnsignedByte();
         bookmark++;

         while( strlength != 0 )
         {
            while( ( strlength & 0x00C0 ) == 192 ) // indicates compressed data
            {
               strlength = (strlength << 8 ) | (int)data.readUnsignedByte(); // offset from mark
               strlength = strlength & 0x003fff;
               //System.out.println( "\nansw.strlength=" + strlength );
               if( !in_bookmark) bookmark++;
               in_bookmark = true;

               data.reset();  // skip back to mark
               data.skipBytes( strlength );
               strlength = (int)data.readUnsignedByte();
            }
            byte[] buffer = new byte[ strlength ];
            data.readFully( buffer );
            if( !in_bookmark) bookmark+=strlength;
            hostname.append( new String(buffer) + "." );
            strlength = (int)data.readUnsignedByte();
            if( !in_bookmark) bookmark++;
         }

         if( in_bookmark) 
         {
         data.reset();
         data.skipBytes( bookmark ); // return to bookmark
         in_bookmark=false;
         }


         rdata.add( hostname.toString() ); 
         
         }
         else if( record_type == 28 ) // TYPE == AAAA
         {

         hostname = new StringBuffer();

         hostname.append( 
            String.format("%04X",(int)data.readUnsignedShort()) + ":" +
            String.format("%04X",(int)data.readUnsignedShort()) + ":" +
            String.format("%04X",(int)data.readUnsignedShort()) + ":" +
            String.format("%04X",(int)data.readUnsignedShort()) + ":" +
            String.format("%04X",(int)data.readUnsignedShort()) + ":" +
            String.format("%04X",(int)data.readUnsignedShort()) + ":" +
            String.format("%04X",(int)data.readUnsignedShort()) + ":" +
            String.format("%04X",(int)data.readUnsignedShort()) );

         bookmark += 16;

         rdata.add( hostname.toString() ); 

         }
         else if( record_type == 1 ) // TYPE == A
         {

         hostname = new StringBuffer();

         hostname.append( 
            (int)data.readUnsignedByte() + "." +
            (int)data.readUnsignedByte() + "." +
            (int)data.readUnsignedByte() + "." +
            (int)data.readUnsignedByte() );

         bookmark += 4;

         rdata.add( hostname.toString() ); 

         }
         else if( record_type==6 ) // TYPE == SOA
         {
         // To process TYPE==6 (SOA) records, use the following format
/*
    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
    /                     MNAME                     /
    /                                               /
    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
    /                     RNAME                     /
    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
    |                    SERIAL                     |
    |                                               |
    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
    |                    REFRESH                    |
    |                                               |
    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
    |                     RETRY                     |
    |                                               |
    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
    |                    EXPIRE                     |
    |                                               |
    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
    |                    MINIMUM                    |
    |                                               |
    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
*/
         // start of authority root name
         hostname = new StringBuffer();

         strlength = (int)data.readUnsignedByte();
         bookmark++;

         while( strlength != 0 )
         {
            while( ( strlength & 0x00C0 ) == 192 ) // indicates compressed data
            {
               strlength = (strlength << 8 ) | (int)data.readUnsignedByte(); // offset from mark
               strlength = strlength & 0x003fff;
               //System.out.println( "\nansw.strlength=" + strlength );
               if( !in_bookmark) bookmark++;
               in_bookmark = true;

               data.reset();  // skip back to mark
               data.skipBytes( strlength );
               strlength = (int)data.readUnsignedByte();
            }
            byte[] buffer = new byte[ strlength ];
            data.readFully( buffer );
            if( !in_bookmark) bookmark+=strlength;
            hostname.append( new String(buffer) + "." );
            strlength = (int)data.readUnsignedByte();
            if( !in_bookmark) bookmark++;
         }

         if( in_bookmark) 
         {
         data.reset();
         data.skipBytes( bookmark ); // return to bookmark
         in_bookmark=false;
         }

         hostname.append( " " );

         // administrator email address

         strlength = (int)data.readUnsignedByte();
         bookmark++;

         while( strlength != 0 )
         {
            while( ( strlength & 0x00C0 ) == 192 ) // indicates compressed data
            {
               strlength = (strlength << 8 ) | (int)data.readUnsignedByte(); // offset from mark
               strlength = strlength & 0x003fff;
               //System.out.println( "\nansw.strlength=" + strlength );
               if( !in_bookmark) bookmark++;
               in_bookmark = true;

               data.reset();  // skip back to mark
               data.skipBytes( strlength );
               strlength = (int)data.readUnsignedByte();
            }
            byte[] buffer = new byte[ strlength ];
            data.readFully( buffer );
            if( !in_bookmark) bookmark+=strlength;
            hostname.append( new String(buffer) + "." );
            strlength = (int)data.readUnsignedByte();
            if( !in_bookmark) bookmark++;
         }

         if( in_bookmark) 
         {
         data.reset();
         data.skipBytes( bookmark ); // return to bookmark
         in_bookmark=false;
         }

         hostname.append( " (" );

         // get numeric data

         hostname.append( 
            (int)data.readInt() + "," +         
            (int)data.readInt() + "," +         
            (int)data.readInt() + "," +         
            (int)data.readInt() + "," +         
            (int)data.readInt() + ")" );         

		bookmark += 20;
			
         rdata.add( hostname.toString() ); 

         } 
		 else if( record_type == 16 || record_type == 13 ) // TXT, HINFO record type
		 {
			 hostname = new StringBuffer();
			 bookmark += rdlength;
			 
			 while( rdlength != 0 ) {
				 int txtlength = data.readUnsignedByte();
				 byte[] buffer = new byte[ txtlength ];
				 data.readFully( buffer );
				 hostname.append( "[" + new String( buffer ) +"]" );
				 rdlength -= (txtlength + 1);
			 }
			 
			 rdata.add( hostname.toString() );
		 }
		 else if( record_type == 0x0101 ) // CAA record type
		 {
			 // Get CAA flags byte
			 hostname = new StringBuffer();
			 
			 int flags = data.readUnsignedByte();
			 bookmark += 1;
			 
			 int taglength = data.readUnsignedByte();
			 bookmark += 1;
			 
			 byte[] tag = new byte[ taglength ];
			 data.readFully( tag );
			 bookmark += taglength;
			 
			 int valuelength = rdlength - taglength - 2;
			 byte[] value = new byte[ valuelength ];
			 data.readFully( value );
			 bookmark += valuelength;
			 
			 hostname.append(
				"0x" + String.format("%02X ", flags) +
				new String( tag ) + " = " +
				new String( value ) );
				
			rdata.add( hostname.toString() );
			 
		 }
		 else {
			 rdata.add( "[not handling " + rdlength + " bytes.]" );
			 data.skipBytes(rdlength);
			 bookmark += rdlength;
		 } //end if

         } // end while

      }
      catch( Exception e )
      {
        System.out.println( "dns_message.constructor2: " + e  );
      }

   }

   public byte[] getBytes( String hostname )
   {
      byte[] prefix = { 0x70, 0x47, 01, 00,
                        00, 01, 00, 00,
                        00, 00, 00, 00 };

      ByteArrayOutputStream output = 
         new ByteArrayOutputStream();

      String[] hostparts = hostname.split("\\.");
      System.out.println( hostname );

      output.write( prefix, 0, prefix.length );
      for(int i=0;i < hostparts.length ; i++)
      {
          output.write( hostparts[i].length() );
          output.write( hostparts[i].getBytes() ,0, hostparts[i].length());
      }
      output.write( 0 );
      output.write( 0 );
      output.write( 255 );
      output.write( 0 );
      output.write( 1 );

      return output.toByteArray();
      
   }

   private static String getQTYPE( int type_code )
   {
      switch( type_code )
      {
      case 1: return "A";
      case 2: return "NS";
      case 3: return "MD";
      case 4: return "MF";
      case 5: return "CNAME";
      case 6: return "SOA";
      case 7: return "MB";
      case 8: return "MG";
      case 9: return "MR";
      case 10: return "NULL";
      case 11: return "WKS";
      case 12: return "PTR";
      case 13: return "HINFO";
      case 14: return "MINFO";
      case 15: return "MX";
      case 16: return "TXT";
	  case 28: return "AAAA";
	  case 46: return "RRSIG";
	  case 48: return "DNSKEY";
	  case 51: return "NSEC3PARAM";
      case 252: return "AXFR";
      case 253: return "MAILB";
      case 254: return "MAILA";
      case 255: return "*";
	  case 0x0101: return "CAA";
      }
      return "##";  // invalid code
       
   }

   private static String getQCLASS( int class_code )
   {
      switch( class_code )
      {
      case 1: return "IN";
      case 2: return "CS";
      case 3: return "CN";
      case 4: return "HS";
      case 255: return "*";
      }
      return "##"; //invalid code
   }

}
