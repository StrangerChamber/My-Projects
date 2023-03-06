function getSymbol() {
    var name = document.getElementById("name");
    name.innerHTML = "";
    var site = document.getElementById("site");
    site.innerHTML = "";
    var stockData = document.getElementById("stockData");
    stockData.innerHTML = "";
  
    var symbol = document.getElementById("inputSymbol").value;
    url = `https://finnhub.io/api/v1/stock/profile2?symbol=${symbol}&token=btkk6cf48v6r1ugbbkng`;
    $.ajax({url:url, dataType: "json"}).then(function(data) {
      console.log(data);
  
      var header = document.getElementById("header");
      header.innerText = data.ticker;
  
      var image = document.getElementById("image");
      image.alt = data.ticker;
      image.src = data.logo;
  
      var title = document.createElement("p");
      title.innerText = data.name;
      title.style = "float: right;";
      name.appendChild(title);
  
      var website = document.createElement("a");
      website.href = data.weburl;
      website.innerText = "Website";
      website.style = "float: left;";
      website.target = "_blank";
      site.appendChild(website);
  
      });
    url = `https://finnhub.io/api/v1/quote?symbol=${symbol}&token=btkk6cf48v6r1ugbbkng`;
    $.ajax({url:url, dataType: "json"}).then(function(data) {
      console.log(data);
  
      var open = document.createElement("p");
      open.innerText = `Open: ${data.o}`;
      stockData.appendChild(open);
  
      var high = document.createElement("p");
      high.innerText = `High: ${data.h}`;
      stockData.appendChild(high);
  
      var low = document.createElement("p");
      low.innerText = `Low: ${data.l}`;
      stockData.appendChild(low);
  
      var close = document.createElement("p");
      close.innerText = `Close: ${data.c}`;
      stockData.appendChild(close);
  
      var pc = document.createElement("p");
      pc.innerText = ` Previous Close: ${data.pc}`;
      stockData.appendChild(pc);
  
      });
  }