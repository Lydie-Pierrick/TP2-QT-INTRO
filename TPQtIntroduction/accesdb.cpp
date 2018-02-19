#include "accesdb.h"

AccesDB AccesDB::m_instance=AccesDB();

AccesDB::AccesDB()
{
    // Init DB
    C_INIT_BD::Creation_BD();

    // Open DB
    db = QSqlDatabase::addDatabase("QSQLITE");

    if(db.isValid())
    {
        db.setHostName("localhost");
        db.setUserName("root");
        db.setPassword("password");

        if(!QFile::exists("base_tmp.sqli"))
            exit(1);

        db.setDatabaseName("base_tmp.sqli");
        db.open();

        if(!db.isOpen())
        {
            qDebug() << db.lastError().text();
            qDebug() << "Erreur à louverture de la base !\n";
        }
    }
}

AccesDB::~AccesDB()
{
}

AccesDB& AccesDB::Instance()
{
    return m_instance;
}

bool AccesDB::addEmployee(QString lastname, QString firstname, int type)
{
    bool b_test = false;
    unsigned int numberOfRows;

    QSqlQuery query(db);

    // Query to get last id determined by the number of line
    query.prepare("SELECT * FROM TRessource");
    query.exec();

    // Number of index
    numberOfRows = 0;

    if(query.last())
    {
        numberOfRows =  query.at() + 2; // In the database C_INIT_D the index begin at 1 not 0
        query.first();
        query.previous();
    }

    // Insert employee
    query.prepare("INSERT INTO TRessource (Id, Nom, Prenom, IdType) "
                      "VALUES (:Id, :Name, :Firstname, :IdType)");
    query.bindValue(":Id", numberOfRows);
    query.bindValue(":Name", lastname);
    query.bindValue(":Firstname", firstname);
    query.bindValue(":IdType", type);

    b_test=query.exec();

    if(!b_test)
    {
        qDebug() << query.lastError().text();
        qDebug() << "Insertion de données dans TRessource impossible !\n";
        return false;
    }

    return true;
}

Employee AccesDB::getEmployeeById(int id)
{
    QSqlQuery query(db);

    Employee employee;

    query.prepare("SELECT Id, Nom, Prenom, IdType FROM TRessource WHERE Id = :Id");
    query.bindValue(":Id", id);
    query.exec();

    employee.setId(query.value(0).toInt());
    employee.setLastname(query.value(1).toString());
    employee.setFirstname(query.value(2).toString());
    employee.setType(query.value(3).toInt());

    return employee;
}

vector<Employee> AccesDB::getEmployeeAll()
{
    QSqlQuery query(db);

    Employee employee;
    vector<Employee> employeeList;

    query.prepare("SELECT Id, Nom, Prenom, IdType FROM TRessource");
    query.exec();

    while (query.next()) {
        employee.setId(query.value(0).toInt());
        employee.setLastname(query.value(1).toString());
        employee.setFirstname(query.value(2).toString());
        employee.setType(query.value(3).toInt());
        employeeList.push_back(employee);
    }

    return employeeList;
}
