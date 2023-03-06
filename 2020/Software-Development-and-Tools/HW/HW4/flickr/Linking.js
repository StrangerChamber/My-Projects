$(document).ready(function(){
    MakeApiCall();
  });

function MakeApiCall(){
   $("form").submit(function(event){
       event.preventDefault();
       var flickrAPIKey = "a4a6fb9bc3e1b41f35c35ea99a6841a8";
       title = $("#txtInput").val();
       limit = $("#amount").val()
       var flickrURL = 'https://www.flickr.com/services/rest/?'+ $.param({
           'method': 'flickr.photos.search',
           'api_key': flickrAPIKey,
           'tags': title,
           'per_page': limit,
           'format': 'json',
           'nojsoncallback': '1'
       });
        $.ajax({url: flickrURL, success: function(arr){
            console.log(arr);
            var photos = $("#photos");
            for (var i = 0; i < arr.length; i++) {
                var image = "<img src=" + encodeURL(arr[i]) + "></img>";
                photos.append(image);
            }
        }
    });

   });
}





