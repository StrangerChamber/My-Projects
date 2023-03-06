//api key: 34ea3e6f
//  http://www.omdbapi.com/?apikey=[<insert your key>]& 
//base link above ^



function getMovies(){
    var title = document.getElementById("movieTitle").value;
    url = 'http://www.omdbapi.com/?apikey=34ea3e6f&t='+title;
    $(document).ready(function() {
        $.ajax({url:url, dataType: "json"}).then(function(data) {
            console.log(data);
            var poster = data.Poster;
            var name = data.Title;
            document.getElementById("movieCard").innerHTML = "<img src=" + poster + " class=" +"card-img-top>" + " <div class="+"card-body"+"> <h5 class="+"card-title"+">"+name+"</h5> <button type="+"button"+" class="+"btn btn-info btn-lg"+" data-toggle="+"modal"+" data-target="+"#myModal"+">Add Review</button> </div>"
          
            //add review pops up a modal form
            //then the form is inserted to DB 
            // and DB populates it into table of reviews page
        });
    });
}

$('#modalSubmit').click(function(){
    window.location.href = "reviews"
});