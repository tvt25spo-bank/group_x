const express=require('express');
const student=require('../models/student_model');

const router=express.Router();

router.get('/',function(request, response){
    student.getAll(function(err, result){
        if(err){
            response.send(err);
        }
        else{
            response.json(result);
        }
    });
});

router.get('/:uname',function(request, response){
    student.getOne(request.params.uname,function(err, result){
        if(err){
            response.send(err);
        }
        else{
            response.json(result[0]);
        }
    });
});

router.post('/',function(request,response){
    console.log(request.body);
    student.add(request.body, function(err, result){
        if(err){
            response.send(err);
        }
        else{
            response.json(result);
        }
    });
});

module.exports=router;