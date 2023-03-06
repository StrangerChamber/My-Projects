var news_array = '';
var category_array = '';
let loaded = false;

/*
  converts the given dateTime (UNIX) into Month, Date, Year
*/
function convertDateTime(dateTime) {
  var time = parseInt(dateTime);
  var temp = new Date(time * 1000);
  var months = ['January', 'Feburary', 'March', 'April', 'May', 'June', 
                'July', 'August', 'September', 'October', 'November', 'December'];
  var year = temp.getFullYear();
  var month = months[temp.getMonth()];
  var date = temp.getDate();
  var final = month + ' ' + date + ', ' + year;
  return final;
}

function loadNewsPage() {
  var url, img, title, summary, time, value;
  var api_url = `https://finnhub.io/api/v1/news?category=general&token=bu6sjt748v6rghl7koq0`;
  $.ajax({url:api_url, dataType: "json"}).then(function(data) {
    news_array = data;
    console.log(news_array);
    for(var i = 0; i < 9; ++i) {
      value = "art" + (i + 1).toString();
  
      url = document.getElementById(value + "URL");
      img = document.getElementById(value + "Img");
      title = document.getElementById(value + "Title");
      summary = document.getElementById(value + "Summary");
      time = document.getElementById(value + "Time");
  
      url.href = news_array[i].url;
      img.src = news_array[i].image;
      title.innerHTML = news_array[i].headline;
      summary.innerHTML = news_array[i].summary;
      time.innerHTML = convertDateTime(news_array[i].datetime);
    }
  })
  loaded = true;

}

/* 
  When a button is clicked on the news page, this will update the articles shown.
*/
function changeNewsPage(pageNum) {
  if(!loaded) {
    alert("Please let the data load before changing pages.");
    return;
  }
  var url, img, title, summary, time, value;

  for(var i = 0; i < 9; ++i) {
    value = "art" + (i + 1).toString();

    url = document.getElementById(value + "URL");
    img = document.getElementById(value + "Img");
    title = document.getElementById(value + "Title");
    summary = document.getElementById(value + "Summary");
    time = document.getElementById(value + "Time");

    url.href = news_array[pageNum*9 + i].url;
    img.src = news_array[pageNum*9 + i].image;
    title.innerHTML = news_array[pageNum*9 + i].headline;
    summary.innerHTML = news_array[pageNum*9 + i].summary;
    time.innerHTML = convertDateTime(news_array[pageNum*9 + i].datetime);
  }

}

/* Registration JavaScript for disabling submit button until required fields are not empty*/
function fields_empty() {
  var fname, lname, uname, pword, pworda, submit;
  fname = document.getElementById("first-name");
  lname = document.getElementById("last-name");
  uname = document.getElementById("username");
  pword = document.getElementById("password");
  pworda = document.getElementById("password-auth");
  submit = document.getElementById("reg-button");
  if (fname.value == "" || lname.value == "" || uname.value == "" || pword.value == "" || pworda.value == "")
  {
    submit.disabled = true;
  }
  if (fname.value != "" && lname.value != "" && uname.value != "" && pword.value != "" && pworda.value != "")
  {
    submit.disabled = false;
  }
}

/* Registration JavaScript for checking password verification. Will not allow submission until passwords match*/
function valid() {
  var pword, pworda;
  pword = document.getElementById("password");
  pworda = document.getElementById("password-auth");
  if (pword.value != pworda.value)
  {
    alert("Passwords do not match!! Please re-enter matching passwords to continue. (ALL FIELDS CASE SENSITIVE)")
    return false;
  }
  else
  {
    return true;
  }
}

/*Trade JavaScript*/

var buyOrSell = 0; //0 means a buy 1 will indicate user wants to sell stock
var ticker = "";

//User selects buy/sell
function showHide(toggle){
  if(toggle == 1){
    buyOrSell = 1;
  }
  else{
    buyOrSell = 0; 
  }
  var userForm = document.getElementById('enterInfo');
  userForm.style.visibility = 'visible';
  var btn = document.getElementById(submitTrade);
  submitTrade.style.visibility = 'visible';
}

//user enters field to trade stock
function update(){
  tkr = document.getElementById('ticker');
  ticker = tkr.value;
  var qty_Str = document.getElementById('qty');
  var qty = parseInt(qty_Str.value);

  //check ticker symbol field isn't blank
  if(ticker == ""){
    alert("You can't leave the ticker field blank");
    tkr.value = "";
    qty_Str.value = "";
    return; 
  }
  
  //invalid input for amount field (qty)
  if(Number.isNaN(qty) || qty <= 0){
    tkr.value = "";
    qty_Str.value = "";
    alert('Enter a valid number greater than 0 for the amount field');
    return; 
  }
  //check if balance is big enough
  // if (!checkFunds(ticker, qty)){
  //   alert("You don't have enough funds for this transaction");
  //   return; 
  // }
  // //update table in db
  // else{

  // }

}

//Check that user has enough funds to purchase stock if buying
// function checkFunds(ticker,qty){
//   var balance = ; //taken from db
//   var stockPrice = ; //get amount per stock from API
//   var totCost = qty * stockPrice; 
//   var remainingBal = balance - totCost;
//   if(remainingBal > 0){
//     return true; 
//   }
//   else{
//     return false; 

//   }

// }


//profile js

//create a table 
function addRows(){

//UPDATE NUM POSITIONS WITH NUMBER OF STOCKS USER OWNS//
  var numPositions = 3; //number of stock positions user has

  var numCol = 5; //HTML will need to be changed if we change column values

   //ticker symbol, qty, price paid, and market value, profit gain/loss
  //for each of the user's positions
  var userStocks = new Array();


  var companies = ['FB','AAPL','NFLX','GOOGL'];

  for(var i =0; i < 4; i ++){
    console.log(companies[i]);
     url = `https://finnhub.io/api/v1/quote?symbol=${companies[i]}&token=btkk6cf48v6r1ugbbkng`;
     console.log(url);
    $.ajax({url:url, dataType: "json"}).then(function(data) {

     
      var close = data.c; //closing price
      //console.log(close);
      console.log(close);
      });
  }


  //UPDATE USERSTOCKS WITH EACH ELEMENT IN ARRAY CORRESPONDING TO
  //STOCK TICKER OWNED, NUM OF STOCKS OWNED, PRICE BOUGHT IN, CURRENT STOCK VALUE, AND PROFITT/LOSS//
  userStocks.push(['APPL','5','100.48','115.48','+15']);
  userStocks.push(['APPL','5','100.48','115.48','+15']);
  userStocks.push(['APPL','5','100.48','115.48','+15']);

  table = document.getElementById("Positions");
  var tr = document.createElement("tr"); //new row

  for(var i =0; i < numPositions; i ++){
    tr = table.insertRow(-1);
    
    for(var j = 0; j < numCol; j ++){
      var td = document.createElement('td');

      td = tr.insertCell(-1);
      td.innerHTML = userStocks[i][j];
      tr.appendChild(td);

    }
    table.appendChild(tr);
  }
}
