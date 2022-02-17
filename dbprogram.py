import sqlite3
from sqlite3 import Error
def sql_link():
    try:
        connection=sqlite3.connect('stats1.db')
        return connection
    except Error:
        print(Error)

def sql_table(connection):
    cursorObj=connection.cursor()
    cursorObj.execute("CREATE TABLE Cricket_stats(Cricket_stats_id n(5),name char(30),country char(20),ranking n(5));")
    cursorObj.executescript("""
    INSERT INTO Cricket_stats VALUES(1,'Kane Williamson','NEW ZEALAND',3);
    INSERT INTO Cricket_stats VALUES(2,'Smith','AUSTRALIA',4);
    INSERT INTO Cricket_stats VALUES(3,'Rahul','INDIA',5);
    INSERT INTO Cricket_stats VALUES(4,'Kohli','INDIA',7);
    """)
    connection.commit()
    cursorObj.execute("SELECT * FROM Cricket_stats")
    rows=cursorObj.fetchall()
    print('Cricket details:')
    for row in rows:
        print(row)
    print("\nUpdate ranking 5 to 39 where id is 3:")
    sql_update_query = """Update Cricket_stats set ranking = 39 where Cricket_stats_id = 03"""
    cursorObj.execute(sql_update_query)
    connection.commit()
    print("Record Updated successfully ")
    cursorObj.execute("SELECT * FROM Cricket_stats")
    rows = cursorObj.fetchall()
    print("\nAfter updating Cricket details:")
    for row in rows:
        print(row)
    print("\nDelete name 'Smith' where Cricket_stats_id=2:")
    sql_delete_query = """DELETE FROM Cricket_stats WHERE Cricket_stats_id = 2"""
    cursorObj.execute(sql_delete_query)
    connection.commit()
    print("Record Deleted successfully ")
    cursorObj.execute("SELECT * FROM Cricket_stats")
    rows = cursorObj.fetchall()
    print("\nAfter deleting Cricket_stats details:")
    for row in rows:
        print(row)

sqllite_conn=sql_link()
sql_table(sqllite_conn)
if(sqllite_conn):
    sqllite_conn.close()
    print('\nSQLite connection is closed')