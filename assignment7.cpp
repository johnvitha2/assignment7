#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>

using namespace std;

void runBatch(sql::Statement* stmt, const vector<string>& v) {
    for (const auto& s : v) {
        if (s.empty()) continue;
        stmt->execute(s);
    }
}

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
    sql::Connection* c = d->connect("tcp://mysql.eecs.ku.edu:3306", "348f25_j243v784", "Thei4uj9");
    c->setSchema("348f25_j243v784");

    sql::Statement* stmt = c->createStatement();

    vector<string> course7sql = {
        "DROP TABLE IF EXISTS Course7",
        "CREATE TABLE Course7 ("
        "CourseNo CHAR(6),"
        "CrsDesc VARCHAR(50),"
        "CrsUnits INT,"
        "PRIMARY KEY (CourseNo)"
        ")",
        "INSERT INTO Course7 (CourseNo, CrsDesc, CrsUnits) VALUES ('FIN300','FUNDAMENTALS OF FINANCE',4)",
        "INSERT INTO Course7 (CourseNo, CrsDesc, CrsUnits) VALUES ('FIN450','PRINCIPLES OF INVESTMENTS',4)",
        "INSERT INTO Course7 (CourseNo, CrsDesc, CrsUnits) VALUES ('FIN480','CORPORATE FINANCE',4)",
        "INSERT INTO Course7 (CourseNo, CrsDesc, CrsUnits) VALUES ('IS320','FUNDAMENTALS OF BUSINESS PROGRAMMING',4)",
        "INSERT INTO Course7 (CourseNo, CrsDesc, CrsUnits) VALUES ('IS460','SYSTEMS ANALYSIS',4)",
        "INSERT INTO Course7 (CourseNo, CrsDesc, CrsUnits) VALUES ('IS470','BUSINESS DATA COMMUNICATIONS',4)",
        "INSERT INTO Course7 (CourseNo, CrsDesc, CrsUnits) VALUES ('IS480','FUNDAMENTALS OF DATABASE MANAGEMENT',4)"
    };

    vector<string> student7sql = {
        "DROP TABLE IF EXISTS Student7",
        "CREATE TABLE Student7 ("
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
        ")",
        "INSERT INTO Student7 (StdNo, StdFirstName, StdLastName, StdCity, StdState, StdMajor, StdClass, StdGPA, StdZip) "
        "VALUES ('876-54-3210','CRISTOPHER','COLAN','SEATTLE','WA','IS','SR',4.00,'98114-1332')",
        "INSERT INTO Student7 (StdNo, StdFirstName, StdLastName, StdCity, StdState, StdMajor, StdClass, StdGPA, StdZip) "
        "VALUES ('890-12-3456','LUKE','BRAZZI','SEATTLE','WA','IS','SR',2.20,'98116-0021')",
        "INSERT INTO Student7 (StdNo, StdFirstName, StdLastName, StdCity, StdState, StdMajor, StdClass, StdGPA, StdZip) "
        "VALUES ('901-23-4567','WILLIAM','PILGRIM','BOTHELL','WA','IS','SO',3.80,'98113-1885')"
    };

    vector<string> faculty7sql = {
        "DROP TABLE IF EXISTS Faculty7",
        "CREATE TABLE Faculty7 ("
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
        ")",
        "INSERT INTO Faculty7 "
        "(FacNo, FacFirstName, FacLastName, FacCity, FacState, FacDept, FacRank, FacSalary, FacSupervisor, FacHireDate, FacZipCode) "
        "VALUES ('098-76-5432','LEONARD','VINCE','SEATTLE','WA','MS','ASST',35000.00,'654-32-1098','2007-04-10','98111-9921')",
        "INSERT INTO Faculty7 "
        "(FacNo, FacFirstName, FacLastName, FacCity, FacState, FacDept, FacRank, FacSalary, FacSupervisor, FacHireDate, FacZipCode) "
        "VALUES ('876-54-3210','CRISTOPHER','COLAN','SEATTLE','WA','MS','ASST',40000.00,'654-32-1098','2011-03-01','98114-1332')",
        "INSERT INTO Faculty7 "
        "(FacNo, FacFirstName, FacLastName, FacCity, FacState, FacDept, FacRank, FacSalary, FacSupervisor, FacHireDate, FacZipCode) "
        "VALUES ('987-65-4321','JULIA','MILLS','SEATTLE','WA','FIN','ASSC',75000.00,'765-43-2109','2012-03-15','98114-9954')"
    };

    vector<string> offering7sql = {
        "DROP TABLE IF EXISTS Offering7",
        "CREATE TABLE Offering7 ("
        "OfferNo INT,"
        "CourseNo CHAR(6),"
        "OffTerm CHAR(6),"
        "OffYear INT,"
        "OffLocation VARCHAR(30),"
        "OffTime VARCHAR(10),"
        "FacNo CHAR(11),"
        "OffDays CHAR(6) DEFAULT 'MW',"
        "PRIMARY KEY (OfferNo)"
        ")",
        "INSERT INTO Offering7 (OfferNo, CourseNo, OffTerm, OffYear, OffLocation, OffTime, FacNo, OffDays) "
        "VALUES (6666,'FIN450','WINTER',2020,'BLM212','10:30:00','987-65-4321','TTH')",
        "INSERT INTO Offering7 (OfferNo, CourseNo, OffTerm, OffYear, OffLocation, OffTime, FacNo, OffDays) "
        "VALUES (7777,'FIN480','SPRING',2020,'BLM305','13:30:00','765-43-2109','MW')",
        "INSERT INTO Offering7 (OfferNo, CourseNo, OffTerm, OffYear, OffLocation, OffTime, FacNo, OffDays) "
        "VALUES (8888,'IS320','SUMMER',2020,'BLM405','13:30:00','654-32-1098','MW')",
        "INSERT INTO Offering7 (OfferNo, CourseNo, OffTerm, OffYear, OffLocation, OffTime, FacNo, OffDays) "
        "VALUES (9876,'IS460','SPRING',2020,'BLM307','13:30:00','654-32-1098','TTH')"
    };

    vector<string> enrollment7sql = {
        "DROP TABLE IF EXISTS Enrollment7",
        "CREATE TABLE Enrollment7 ("
        "OfferNo INT,"
        "StdNo CHAR(11),"
        "EnrGrade DECIMAL(3,2),"
        "PRIMARY KEY (OfferNo, StdNo)"
        ")",
        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (1234,'123-45-6789',3.30)",
        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (1234,'234-56-7890',3.50)",
        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (1234,'345-67-8901',3.20)",
        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (1234,'456-78-9012',3.10)",
        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (1234,'567-89-0123',3.80)",
        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (1234,'678-90-1234',3.40)",

        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (4321,'123-45-6789',3.50)",
        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (4321,'124-56-7890',3.20)",
        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (4321,'789-01-2345',3.50)",
        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (4321,'876-54-3210',3.10)",
        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (4321,'890-12-3456',3.40)",
        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (4321,'901-23-4567',3.10)",

        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (5555,'123-45-6789',3.20)",
        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (5555,'124-56-7890',2.70)",

        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (5678,'123-45-6789',3.20)",
        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (5678,'234-56-7890',2.80)",
        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (5678,'345-67-8901',3.30)",
        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (5678,'456-78-9012',3.40)",
        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (5678,'567-89-0123',2.60)",

        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (5679,'123-45-6789',2.00)",
        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (5679,'124-56-7890',3.70)",
        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (5679,'678-90-1234',3.30)",
        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (5679,'789-01-2345',3.80)",
        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (5679,'890-12-3456',2.9)",
        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (5679,'901-23-4567',3.1)",

        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (6666,'234-56-7890',3.1)",
        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (6666,'567-89-0123',3.6)",

        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (7777,'876-54-3210',3.4)",
        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (7777,'890-12-3456',3.7)",
        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (7777,'901-23-4567',3.4)",

        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (9876,'124-56-7890',3.5)",
        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (9876,'234-56-7890',3.2)",
        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (9876,'345-67-8901',3.2)",
        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (9876,'456-78-9012',3.4)",
        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (9876,'567-89-0123',2.6)",
        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (9876,'678-90-1234',3.3)",
        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (9876,'901-23-4567',4.0)",

        "INSERT INTO Enrollment7 (OfferNO, StdNo, EnrGrade) VALUES (1111,'901-23-4567',0.0)"
    };

    runBatch(stmt, course7sql);
    runBatch(stmt, student7sql);
    runBatch(stmt, faculty7sql);
    runBatch(stmt, offering7sql);
    runBatch(stmt, enrollment7sql);

    vector<pair<int,string>> q = {
        {1,"SELECT * FROM Student7 WHERE StdMajor='IS'"},
        {2,"SELECT StdNo FROM Enrollment7 GROUP BY StdNo HAVING COUNT(OfferNo)>2"},
        {3,"SELECT FacFirstName,FacLastName FROM Faculty7 WHERE YEAR('2025-01-01')-YEAR(FacHireDate)>15 OR YEAR(FacHireDate)<=2010"},
        {4,"SELECT CourseNo FROM Offering7 WHERE OffTerm='SUMMER' AND OffYear=2020"},
        {5,"SELECT FacFirstName,FacLastName FROM Faculty7 WHERE FacZipCode LIKE '98114%'"}, 
        {6,"SELECT MAX(StdGPA) FROM Student7 WHERE StdGPA < (SELECT MAX(StdGPA) FROM Student7)"},
        {7,"SELECT s.StdFirstName,s.StdLastName FROM Student7 s INNER JOIN Faculty7 f ON s.StdFirstName=f.FacFirstName AND s.StdLastName=f.FacLastName"},
        {8,"SELECT s.StdNo,s.StdFirstName,s.StdLastName,COUNT(e.OfferNo) FROM Student7 s LEFT JOIN Enrollment7 e ON s.StdNo=e.StdNo GROUP BY s.StdNo"},
        {9,"SELECT FacFirstName,FacLastName,FacSalary FROM Faculty7 ORDER BY FacSalary DESC LIMIT 3"},
        {10,"SELECT * FROM Student7 WHERE StdNo NOT IN (SELECT StdNo FROM Enrollment7)"},
        {11,"INSERT INTO Student7 VALUES('888-88-8888','ALICE','SMITH','TOPEKA','KS','66610','CS','JR',3.85)"},
        {11,"SELECT * FROM Student7"},
        {12,"UPDATE Student7 SET StdCity='OVERLAND PARK',StdZip='66202' WHERE StdFirstName='BOB' AND StdLastName='NORBERT'"},
        {12,"SELECT * FROM Student7"}
    };

    for (auto& x : q) {
        cout << x.first << ". " << x.second << endl;
        bool hasResult = stmt->execute(x.second);
        if (hasResult) {
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






