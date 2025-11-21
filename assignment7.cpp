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
        {11, "SELECT * FROM Student7"},
        {12, "UPDATE Student7 SET StdCity='OVERLAND PARK',StdZip='66202' WHERE StdFirstName='BOB' AND StdLastName='NORBERT'"},
        {12, "SELECT * FROM Student7"}
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






