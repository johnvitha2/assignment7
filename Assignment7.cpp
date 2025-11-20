#include <iostream>
#include <vector>
#include <string>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>

using namespace std;

void runQueries(sql::Statement* stmt, const vector<string>& q) {
    for (auto& s : q) {
        if (s.size() == 0) continue;
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
    sql::Connection* c = d->connect(
        "tcp://mysql.eecs.ku.edu:3306",
        "348f25_j243v784",
        "Thei4uj9"
    );

    c->setSchema("348f25_j243v784");

    sql::Statement* stmt = c->createStatement();

    vector<string> course7sql = {
        "DROP TABLE IF EXISTS Course7",
        "CREATE TABLE Course7 (CourseNo CHAR(8) NOT NULL, CrsDesc VARCHAR(50), CrsUnits INT, PRIMARY KEY(CourseNo))"
    };

    vector<string> student7sql = {
        "DROP TABLE IF EXISTS Student7",
        "CREATE TABLE Student7 (StdNo CHAR(11) NOT NULL, StdFirstName VARCHAR(20), StdLastName VARCHAR(20), StdCity VARCHAR(20), StdState CHAR(2), StdZip CHAR(5), StdMajor CHAR(4), StdClass CHAR(2), StdGPA FLOAT, PRIMARY KEY(StdNo))"
    };

    vector<string> faculty7sql = {
        "DROP TABLE IF EXISTS Faculty7",
        "CREATE TABLE Faculty7 (FacSSN CHAR(11) NOT NULL, FacFirstName VARCHAR(20), FacLastName VARCHAR(20), FacCity VARCHAR(20), FacState CHAR(2), FacZipCode CHAR(5), FacHireDate DATE, FacRank CHAR(4), FacSalary FLOAT, PRIMARY KEY(FacSSN))"
    };

    vector<string> offering7sql = {
        "DROP TABLE IF EXISTS Offering7",
        "CREATE TABLE Offering7 (OfferNo CHAR(8) NOT NULL, CourseNo CHAR(8), OffTerm CHAR(10), OffYear INT, FacSSN CHAR(11), PRIMARY KEY(OfferNo))"
    };

    vector<string> enrollment7sql = {
        "DROP TABLE IF EXISTS Enrollment7",
        "CREATE TABLE Enrollment7 (StdNo CHAR(11), OfferNo CHAR(8))"
    };

    runQueries(stmt, course7sql);
    runQueries(stmt, student7sql);
    runQueries(stmt, faculty7sql);
    runQueries(stmt, offering7sql);
    runQueries(stmt, enrollment7sql);

    vector<pair<int,string>> q = {
        {1,"SELECT * FROM Student7 WHERE StdMajor='IS'"},
        {2,"SELECT StdNo FROM Enrollment7 GROUP BY StdNo HAVING COUNT(OfferNo)>2"},
        {3,"SELECT FacFirstName,FacLastName FROM Faculty7 WHERE YEAR('2025-01-01')-YEAR(FacHireDate)>15 OR YEAR(FacHireDate)<=2010"},
        {4,"SELECT CourseNo FROM Offering7 WHERE OffTerm='SUMMER' AND OffYear=2020"},
        {5,"SELECT FacFirstName,FacLastName FROM Faculty7 WHERE FacZipCode='98114'"},
        {6,"SELECT MAX(StdGPA) FROM Student7 WHERE StdGPA < (SELECT MAX(StdGPA) FROM Student7)"},
        {7,"SELECT s.StdFirstName,s.StdLastName FROM Student7 s INNER JOIN Faculty7 f ON s.StdFirstName=f.FacFirstName AND s.StdLastName=f.FacLastName"},
        {8,"SELECT s.StdNo,s.StdFirstName,s.StdLastName,COUNT(e.OfferNo) FROM Student7 s LEFT JOIN Enrollment7 e ON s.StdNo=e.StdNo GROUP BY s.StdNo"},
        {9,"SELECT FacFirstName,FacLastName,FacSalary FROM Faculty7 ORDER BY FacSalary DESC LIMIT 3"},
        {10,"SELECT * FROM Student7 WHERE StdNo NOT IN (SELECT StdNo FROM Enrollment7)"},
        {{11,"INSERT INTO Student7 VALUES('888-88-8888','ALICE','SMITH','TOPEKA','KS','66610','CS','JR',3.85')"},
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

