const db = require('../database');
const bcrypt = require('bcryptjs');
const saltrounds = 12;

const student = {

    getAll: function(callback) {
        return db.query("SELECT * FROM student",callback);
    },
    getOne: function(un,callback) {
        return db.query("SELECT * FROM student WHERE username=?",[un],callback);
    },
    add: function(stu, callback) {
        bcrypt.hash(stu.password, saltrounds, function (err, hashed) {
            if (err) {
                return callback(err.message);
            }
            else {
                return db.query("INSERT INTO student VALUES(?,?,?,?,?,?,?)", [
                    stu.username,
                    stu.fname,
                    stu.lname,
                    stu.streetaddress,
                    stu.email,
                    hashed,
                    stu.role
                ], callback);
            }
        });
    }
}

module.exports = student;