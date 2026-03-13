const db=require('../database');

const grade={

    getOwnGrades:function(un, callback){
        db.query("SELECT course_name, grade, DATE_FORMAT(grade_date,'%d.%m.%Y') as grade_date FROM student INNER JOIN grade ON student.username=grade.username INNER JOIN course ON grade.idcourse=course.idcourse WHERE student.username=?", [un],callback);
    }
}

module.exports=grade;