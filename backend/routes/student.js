const express=require('express');
const student=require('../models/student_model');

const router=express.Router();

router.get('/',function(request, response){
    console.log(request.user);
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
    console.log(request.user);
    if(request.user.role!='admin' && request.user.role!='teacher'){
        return response.status(401).json({"error":"sinulla ei ole oikeutta tähän resurssiin"});
    }
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