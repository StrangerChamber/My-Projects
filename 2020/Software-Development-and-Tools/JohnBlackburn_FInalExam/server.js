var express = require('express'); //Ensure our express framework has been added
var app = express();
var bodyParser = require('body-parser'); //Ensure our body-parser tool has been added
app.use(bodyParser.json());              // support json encoded bodies
app.use(bodyParser.urlencoded({ extended: true })); // support encoded bodies

//Create Database Connection
var pgp = require('pg-promise')();




let dbConfig = {
     host: process.env.LOCAL_DB_HOST,
      port: process.env.LOCAL_DB_PORT,
      database: process.env.LOCAL_DB_NAME,
      user: process.env.LOCAL_DB_USER,
      password: process.env.LOCAL_DB_PASSWORD
     };

const isProduction = process.env.NODE_ENV === 'production';
dbConfig = isProduction ? process.env.DATABASE_URL : dbConfig;
let db = pgp(dbConfig);

// set the view engine to ejs
app.set('view engine', 'ejs');
app.use(express.static(__dirname + '/'));






app.get('/', function(req, res) {
    res.render('Pages/main',{
       
    });
  });

  app.get('/reviews', function(req, res) {
    res.render('Pages/reviews',{
       
    });
  });



//insert data to db from modal
  app.post('/main/modalForm', function(req,res){
      var title = req.body.title;
      var review = req.body.review;
      var insert = "Insert into movies (title, review) values ('"+title+"' , '"+review+"');";
      db.task('get-everything', task => {
        return task.batch([
            task.any(insert)
            ]);
        }) .then(info=> {
            res.render('Views/Pages/reviews',{
				
			})
        .catch(function(err){
            console.log("error message")
        });
    });
});

//populate table with all reviews
app.get('/main/modalForm', function(req, res) {
	var query = 'select * from movies;';
	db.any(query)
        .then(info=> {
            res.render('Views/Pages/reviews',{
				data: info,
			
			})

        })
        .catch(function (err) {
            console.log('error', err);
            res.render('Views/Pages/reviews', {
                
            })
        })
});
  





const PORT = process.env.PORT || 8080;

const server = app.listen(PORT, () => {
  console.log(`Express running → PORT ${server.address().port}`);
});
