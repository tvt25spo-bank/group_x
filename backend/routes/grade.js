const express=require('express');
const grade=require('../models/grade_model');

const router=express.Router();

router.get('/:uname', function(request, response){
    //saa katsoa vain omat arvosanat
    if(request.params.uname != request.user.username){
        return response.status(401).json({"error":"sinulla ei ole oikeutta tähän resurssiin"});
    }
    grade.getOwnGrades(request.params.uname, function(err,result){
        if(err){
            response.send(err);
        }
        else{
            response.json(result);
        }
    });
});

module.exports=router;