const express=require('express');
const PORT=3000;
const studentRouter=require('./routes/student');
const loginRouter=require('./routes/login');

const app=express();

app.use(express.json());

app.get('/',function(request,response){
    response.send("Peppi esimerkki");
});

app.use('/login',loginRouter);
app.use('/student',studentRouter);


app.listen(PORT,function(){
    console.log("Palvelin kuuntelee porttia:"+PORT);
});

module.exports=app;