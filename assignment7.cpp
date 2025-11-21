#include <iostream>
#include <string>
#include <vector>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>

using namespace std;

void printResult(sql::ResultSet* r) {
    sql::ResultSetMetaData* m = r->getMetaData();
    int n = m->getColumnCount();
    while (r->next()) {
        for (int i = 1; i <= n; i++) {
            cout << r->getString(i);
            if (i < n) cout << " ";
        }
        cout << endl;
    }
}

int main() {
    sql::mysql::MySQL_Driver* d = sql::mysql::get_mysql_driver_instance();
    sql::Connection* c = d->connect(
        "tcp://mysql.eecs.ku.edu:3306",
        "348f25_j243v784",
        "Thei4uj9"
    );

    c->setSchema("348f25_j243v784");
    sql::Statement* stmt = c->createStatement();

    stmt->execute(
        "CREATE TABLE IF NOT EXISTS Course7 ("
        "CourseNo VARCHAR(10),"
        "CrsDesc VARCHAR(50),"
        "CrsUnits INTEGER,"
        "PRIMARY KEY (CourseNo)"
        ");"
    );
    stmt->execute("INSERT INTO Course7 VALUES ('FIN300','FUNDAMENTALS OF FINANCE',4);");
    stmt->execute("INSERT INTO Course7 VALUES ('FIN450','PRINCIPLES OF INVESTMENTS',4);");
    stmt->execute("INSERT INTO Course7 VALUES ('FIN480','CORPORATE FINANCE',4);");
    stmt->execute("INSERT INTO Course7 VALUES ('IS320','FUNDAMENTALS OF BUSINESS PROGRAMMING',4);");
    stmt->execute("INSERT INTO Course7 VALUES ('IS460','SYSTEMS ANALYSIS',4);");
    stmt->execute("INSERT INTO Course7 VALUES ('IS470','BUSINESS DATA COMMUNICATIONS',4);");
    stmt->execute("INSERT INTO Course7 VALUES ('IS480','FUNDAMENTALS OF DATABASE MANAGEMENT',4);");

    stmt->execute(
        "CREATE TABLE IF NOT EXISTS Enrollment7 ("
        "OfferNo INTEGER,"
        "StdNo CHAR(11),"
        "EnrGrade DECIMAL(3,2),"
        "PRIMARY KEY (OfferNo, StdNo)"
        ");"
    );
    stmt->execute("INSERT INTO Enrollment7 VALUES (1234,'123-45-6789',3.30);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (1234,'234-56-7890',3.50);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (1234,'345-67-8901',3.20);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (1234,'456-78-9012',3.10);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (1234,'567-89-0123',3.80);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (1234,'678-90-1234',3.40);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (4321,'123-45-6789',3.50);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (4321,'124-56-7890',3.20);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (4321,'789-01-2345',3.50);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (4321,'876-54-3210',3.10);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (4321,'890-12-3456',3.40);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (4321,'901-23-4567',3.10);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (5555,'123-45-6789',3.20);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (5555,'124-56-7890',2.70);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (5678,'123-45-6789',3.20);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (5678,'234-56-7890',2.80);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (5678,'345-67-8901',3.30);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (5678,'456-78-9012',3.40);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (5678,'567-89-0123',2.60);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (5679,'123-45-6789',2.00);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (5679,'124-56-7890',3.70);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (5679,'678-90-1234',3.30);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (5679,'789-01-2345',3.80);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (5679,'890-12-3456',2.90);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (5679,'901-23-4567',3.10);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (6666,'234-56-7890',3.10);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (6666,'567-89-0123',3.60);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (7777,'876-54-3210',3.40);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (7777,'890-12-3456',3.70);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (7777,'901-23-4567',3.40);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (9876,'124-56-7890',3.50);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (9876,'234-56-7890',3.20);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (9876,'345-67-8901',3.20);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (9876,'456-78-9012',3.40);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (9876,'567-89-0123',2.60);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (9876,'678-90-1234',3.30);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (9876,'901-23-4567',4.00);");
    stmt->execute("INSERT INTO Enrollment7 VALUES (1111,'901-23-4567',0.00);");

    stmt->execute(
        "CREATE TABLE IF NOT EXISTS Faculty7 ("
        "FacNo CHAR(11),"
        "FacFirstName VARCHAR(30),"
        "FacLastName VARCHAR(30),"
        "FacCity VARCHAR(30),"
        "FacState CHAR(2),"
        "FacDept CHAR(10),"
        "FacRank CHAR(4),"
        "FacSalary DECIMAL(10,2),"
        "FacSupervisor CHAR(11),"
        "FacHireDate DATE,"
        "FacZipCode CHAR(10),"
        "PRIMARY KEY (FacNo)"
        ");"
    );
    stmt->execute("INSERT INTO Faculty7 VALUES ('543-21-0987','VICTORIA','EMMANUEL','BOTHELL','WA','MS','PROF',120000.0,NULL,'2008-04-15','98011-2242');");
    stmt->execute("INSERT INTO Faculty7 VALUES ('765-43-2109','NICKI','MACON','BELLEVUE','WA','FIN','PROF',65000.00,NULL,'2009-04-11','98015-9945');");
    stmt->execute("INSERT INTO Faculty7 VALUES ('654-32-1098','LEONARD','FIBON','SEATTLE','WA','MS','ASSC',70000.00,'543-21-0987','2006-05-01','98121-0094');");
    stmt->execute("INSERT INTO Faculty7 VALUES ('098-76-5432','LEONARD','VINCE','SEATTLE','WA','MS','ASST',35000.00,'654-32-1098','2007-04-10','98111-9921');");
    stmt->execute("INSERT INTO Faculty7 VALUES ('876-54-3210','CRISTOPHER','COLAN','SEATTLE','WA','MS','ASST',40000.00,'654-32-1098','2011-03-01','98114-1332');");
    stmt->execute("INSERT INTO Faculty7 VALUES ('987-65-4321','JULIA','MILLS','SEATTLE','WA','FIN','ASSC',75000.00,'765-43-2109','2012-03-15','98114-9954');");

    stmt->execute(
        "CREATE TABLE IF NOT EXISTS Offering7 ("
        "OfferNo INTEGER,"
        "CourseNo CHAR(6),"
        "OffTerm CHAR(6),"
        "OffYear INTEGER,"
        "OffLocation VARCHAR(30),"
        "OffTime VARCHAR(10),"
        "FacNo CHAR(11),"
        "OffDays CHAR(6) DEFAULT 'MW',"
        "PRIMARY KEY (OfferNo)"
        ");"
    );
    stmt->execute("INSERT INTO Offering7 VALUES (1111,'IS320','SUMMER',2020,'BLM302','10:30:00',NULL,'MW');");
    stmt->execute("INSERT INTO Offering7 VALUES (1234,'IS320','FALL',2019,'BLM302','10:30:00','098-76-5432','MW');");
    stmt->execute("INSERT INTO Offering7 VALUES (2222,'IS460','SUMMER',2019,'BLM412','13:30:00',NULL,'TTH');");
    stmt->execute("INSERT INTO Offering7 VALUES (3333,'IS320','SPRING',2020,'BLM214','08:30:00','098-76-5432','MW');");
    stmt->execute("INSERT INTO Offering7 VALUES (4321,'IS320','FALL',2019,'BLM214','15:30:00','098-76-5432','TTH');");
    stmt->execute("INSERT INTO Offering7 VALUES (4444,'IS320','WINTER',2020,'BLM302','15:30:00','543-21-0987','TTH');");
    stmt->execute("INSERT INTO Offering7 VALUES (5555,'FIN300','WINTER',2020,'BLM207','08:30:00','765-43-2109','MW');");
    stmt->execute("INSERT INTO Offering7 VALUES (5678,'IS480','WINTER',2020,'BLM302','10:30:00','987-65-4321','MW');");
    stmt->execute("INSERT INTO Offering7 VALUES (5679,'IS480','SPRING',2020,'BLM412','15:30:00','876-54-3210','TTH');");
    stmt->execute("INSERT INTO Offering7 VALUES (6666,'FIN450','WINTER',2020,'BLM212','10:30:00','987-65-4321','TTH');");
    stmt->execute("INSERT INTO Offering7 VALUES (7777,'FIN480','SPRING',2020,'BLM305','13:30:00','765-43-2109','MW');");
    stmt->execute("INSERT INTO Offering7 VALUES (8888,'IS320','SUMMER',2020,'BLM405','13:30:00','654-32-1098','MW');");
    stmt->execute("INSERT INTO Offering7 VALUES (9876,'IS460','SPRING',2020,'BLM307','13:30:00','654-32-1098','TTH');");

    stmt->execute(
        "CREATE TABLE IF NOT EXISTS Student7 ("
        "StdNo CHAR(11),"
        "StdFirstName VARCHAR(50),"
        "StdLastName VARCHAR(50),"
        "StdCity VARCHAR(50),"
        "StdState CHAR(2),"
        "StdZip CHAR(10),"
        "StdMajor CHAR(6),"
        "StdClass CHAR(6),"
        "StdGPA DECIMAL(3,2) DEFAULT 0,"
        "PRIMARY KEY (StdNo)"
        ");"
    );
    stmt->execute("INSERT INTO Student7 VALUES ('123-45-6789','HOMER','WELLS','SEATTLE','WA','98121-1111','IS','FR',3.00);");
    stmt->execute("INSERT INTO Student7 VALUES ('124-56-7890','BOB','NORBERT','BOTHELL','WA','98011-2121','FIN','JR',2.70);");
    stmt->execute("INSERT INTO Student7 VALUES ('234-56-7890','CANDY','KENDALL','TACOMA','WA','99042-3321','ACCT','JR',3.50);");
    stmt->execute("INSERT INTO Student7 VALUES ('345-67-8901','WALLY','KENDALL','SEATTLE','WA','98123-1141','IS','SR',2.80);");
    stmt->execute("INSERT INTO Student7 VALUES ('456-78-9012','JOE','ESTRADA','SEATTLE','WA','98121-2333','FIN','SR',3.20);");
    stmt->execute("INSERT INTO Student7 VALUES ('567-89-0123','MARIAH','DODGE','SEATTLE','WA','98114-0021','IS','JR',3.60);");
    stmt->execute("INSERT INTO Student7 VALUES ('678-90-1234','TESS','DODGE','REDMOND','WA','98116-2344','ACCT','SO',3.30);");
    stmt->execute("INSERT INTO Student7 VALUES ('789-01-2345','ROBERTO','MORALES','SEATTLE','WA','98121-2212','FIN','JR',2.50);");
    stmt->execute("INSERT INTO Student7 VALUES ('876-54-3210','CRISTOPHER','COLAN','SEATTLE','WA','98114-1332','IS','SR',4.00);");
    stmt->execute("INSERT INTO Student7 VALUES ('890-12-3456','LUKE','BRAZZI','SEATTLE','WA','98116-0021','IS','SR',2.20);");
    stmt->execute("INSERT INTO Student7 VALUES ('901-23-4567','WILLIAM','PILGRIM','BOTHELL','WA','98113-1885','IS','SO',3.80);");

    vector<pair<int,string>> q = {
        {1,  "SELECT * FROM Student7 WHERE StdMajor='IS'"},
        {2,  "SELECT StdNo FROM Enrollment7 GROUP BY StdNo HAVING COUNT(OfferNo)>2"},
        {3,  "SELECT FacFirstName,FacLastName FROM Faculty7 WHERE YEAR('2025-01-01')-YEAR(FacHireDate)>15 OR YEAR(FacHireDate)<=2010"},
        {4,  "SELECT CourseNo FROM Offering7 WHERE OffTerm='SUMMER' AND OffYear=2020"},
        {5,  "SELECT FacFirstName,FacLastName FROM Faculty7 WHERE FacZipCode LIKE '98114%'"},
        {6,  "SELECT MAX(StdGPA) FROM Student7 WHERE StdGPA < (SELECT MAX(StdGPA) FROM Student7)"},
        {7,  "SELECT s.StdFirstName,s.StdLastName FROM Student7 s INNER JOIN Faculty7 f ON s.StdFirstName=f.FacFirstName AND s.StdLastName=f.FacLastName"},
        {8,  "SELECT s.StdNo,s.StdFirstName,s.StdLastName,COUNT(e.OfferNo) FROM Student7 s LEFT JOIN Enrollment7 e ON s.StdNo=e.StdNo GROUP BY s.StdNo"},
        {9,  "SELECT FacFirstName,FacLastName,FacSalary FROM Faculty7 ORDER BY FacSalary DESC LIMIT 3"},
        {10, "SELECT * FROM Student7 WHERE StdNo NOT IN (SELECT StdNo FROM Enrollment7)"},
        {11, "INSERT INTO Student7 VALUES('888-88-8888','ALICE','SMITH','TOPEKA','KS','66610','CS','JR',3.85)"},
        {12, "SELECT * FROM Student7"},
        {13, "UPDATE Student7 SET StdCity='OVERLAND PARK',StdZip='66202' WHERE StdFirstName='BOB' AND StdLastName='NORBERT'"},
        {14, "SELECT * FROM Student7"}
    };

    for (auto& x : q) {
        cout << x.first << ". " << x.second << endl;
        bool has = stmt->execute(x.second);
        if (has) {
            sql::ResultSet* r = stmt->getResultSet();
            printResult(r);
            delete r;
        }
        cout << endl;
    }

    delete stmt;
    delete c;
    return 0;
}







