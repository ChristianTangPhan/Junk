// Global Variables
let wheel = document.querySelector('.wheel');
let spin  = document.getElementById('spin');
let game_data = []; // List of games and the players statuses
let rotation  = 0;  // Rotation of the wheel

// Spin button
spin.onclick = function ()
{
  let random_spin; // Random spin amount

  random_spin = Math.floor(Math.random() * 3600) + 360;
  rotation += random_spin;
  wheel.style.transform = `rotate(${rotation}deg)`;
};

// Next button
document.getElementById("next-button").addEventListener("click", function ()
{
  let selected_players; // Check which boxes are selected
  let player_list;      //
  let game_list;

  // Get selected players from checkboxes
  selected_players = document.querySelectorAll('#checkbox-container input[type=checkbox]:checked');
  player_list      = Array.from(selected_players).map(cb => cb.value);

  // Error if no players selected
  //if (player_list.length === 0)
  //{
  //  alert("Please select at least one player.");
  //  return;
  //}

  // Create the filtered game list
  game_list = filter_games(game_data, player_list, headers);

  // Error if there are no games in the list
  //if (game_list.length === 0)
  //{
  //  alert("No games found for selected players.");
  //  return;
  //}

  // Create the wheel
  create_wheel(game_list);

  // Show the wheel screen
  document.getElementById("select-screen").style.display = "none";
  document.getElementById("wheel-screen").style.display = "block";
  rotation = 0;
  wheel.style.transform = `rotate(0deg)`;
});

// Get Data from google sheet
window.addEventListener('DOMContentLoaded', init);
function init()
{
  let database_url; // Googlesheets link to the database
  let jsonData;    // IDEK

  database_url = `https://docs.google.com/spreadsheets/d/1fxyVMzq81YCyc6cuKsTqVy0yYWRcl_5oTdyOOlSot0Y/gviz/tq?tqx=out:json`;

  // TBH this game from chatgpt
  fetch(database_url)
    .then(response => response.text())
    .then(dataText =>
    {
      jsonData = JSON.parse(dataText.substring(47, dataText.length - 2));
      headers = jsonData.table.cols.map(col => col.label);
      game_data = jsonData.table.rows;
      process_games(game_data, headers);
    })
    .catch(err => {
      console.error('Error loading Google Sheet data:', err);
    });
}

// Parse data
function process_games(rows, headers)
{
  let player_names;
  let checkboxContainer;
  let label;

  player_names = headers.slice(2);
  checkboxContainer = document.getElementById('checkbox-container')

  // Error if there are no check boxes
  //if (!checkboxContainer)
  //{
  //  console.error('No element with id "checkbox-container" found');
  //  return;
  //}

  // Clear existing checkboxes (in case of reload)
  checkboxContainer.innerHTML = '';

  player_names.forEach(player =>
  {
    label = document.createElement('label');
    label.innerHTML = `
      <input type="checkbox" name="player" value="${player}" />
      ${player}
    `;
    checkboxContainer.appendChild(label);
    checkboxContainer.appendChild(document.createElement('br'));
  });
}

// Filter game data into list
function filter_games(rows, players, headers)
{
  let playerIndices;
  let cell;

  // Find column indices for selected players
  playerIndices = players.map(player => headers.indexOf(player));

  // Filter rows (skip header row if included)
  return rows.filter(row =>
  {
    // row.c is array of cells, check if all player columns are 'y' or 'Y'
    return playerIndices.every(idx =>
    {
      cell = row.c[idx];
      return cell && (cell.v === 'y' || cell.v === 'Y');
    });
  });
}

function create_wheel(game_list)
{
  let base_font_size;
  let font_scale;
  let game_name;
  let scale_factor;
  let slice;
  let slice_amount;
  let slice_angle;

  base_font_size = 20;
  slice_amount = game_list.length;
  slice_angle = 360 / slice_amount;
  font_scale = Math.min(1, 12 / slice_amount); // shrink font for many slices
  scale_factor = Math.min(1, 12 / slice_amount); // shrink slices for many

  // Clear wheel
  wheel.innerHTML = '';

  // Helper function: calculates clip-path polygon for a pie slice
  function getSliceClipPath(slices, index) {
    const anglePerSlice = 360 / slices;
    const startAngle = anglePerSlice * index - 90;  // Start at top (rotate -90deg)
    const endAngle = startAngle + anglePerSlice;

    // Convert degrees to radians
    const startRad = (Math.PI / 180) * startAngle;
    const endRad = (Math.PI / 180) * endAngle;

    // Center of circle is at 50% 50%
    // Points on circumference:
    const x1 = 50 + 50 * Math.cos(startRad);
    const y1 = 50 + 50 * Math.sin(startRad);
    const x2 = 50 + 50 * Math.cos(endRad);
    const y2 = 50 + 50 * Math.sin(endRad);

    // Polygon from center to these points (clockwise)
    return `polygon(50% 50%, ${x1}% ${y1}%, ${x2}% ${y2}%)`;
  }

  game_list.forEach((row, i) =>
  {
    game_name = row.c[1] ? row.c[1].v : 'Re-roll';

    slice = document.createElement('div');
    slice.className = 'slice';
    slice.textContent = game_name;

    slice.style.position = 'absolute';
    slice.style.width = '100%';
    slice.style.height = '100%';           // Full circle size
    slice.style.left = '0';                // Position relative to wheel
    slice.style.top = '0';
    slice.style.borderRadius = '50%';     // Make it a circle
    slice.style.backgroundColor = getColor(i);

    // This clip-path cuts the circle into a pie slice
    slice.style.clipPath = getSliceClipPath(slice_amount, i);

    // Rotate each slice so text orientation looks good
    slice.style.transform = `
      rotate(${slice_angle * i}deg)
      scale(${scale_factor})
    `;

    // Center text inside slice
    slice.style.display = 'flex';
    slice.style.alignItems = 'center';
    slice.style.justifyContent = 'center';
    slice.style.textAlign = 'center';

    // Rotate text back to be horizontal inside slice
    slice.style.color = 'black';
    slice.style.fontWeight = 'bold';
    slice.style.fontSize = `${base_font_size * font_scale}px`;
    slice.style.textShadow = '0 0 2px #fff';
    slice.style.userSelect = 'none';

    // Rotate text back opposite to slice rotation so it's readable
    slice.style.writingMode = 'horizontal-tb';  // reset vertical writing
    slice.style.transformOrigin = '50% 50%';

    // Create inner text wrapper to rotate text back upright
    const textWrapper = document.createElement('div');
    textWrapper.style.transform = `rotate(${-slice_angle * i}deg)`;
    textWrapper.style.width = '100%';
    textWrapper.style.textAlign = 'center';
    textWrapper.style.pointerEvents = 'none'; // So clicks go to slice

    textWrapper.textContent = game_name;
    slice.textContent = ''; // clear text in slice itself
    slice.appendChild(textWrapper);

    wheel.appendChild(slice);
  });
}


// Color selecter
function getColor(index)
{
  let colors;
  colors = ['#3f51b5', '#ff9800', '#e91e63', '#4caf50', '#009688', '#795548', '#9c27b0', '#f44336'];
  return colors[index % colors.length];
}

// Return button
document.getElementById("return-button").addEventListener("click", function ()
{
  document.getElementById("select-screen").style.display = "block";
  document.getElementById("wheel-screen").style.display = "none";
});