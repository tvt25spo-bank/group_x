const mysql=require('mysql2');
const connectionString='mysql://peppiuser:peppipass@127.0.0.1/bank_db';

const connection=mysql.createPool(connectionString);

module.exports=connection;