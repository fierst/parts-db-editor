# Database Information
---

The actual database containing the part information is stored in a MariaDB instance that we host locally. The `PartsTablesSchema.sql` file contains the SQL queries required to instantiate the tables within the database.

The tables were largely chosen based on supplier categories and commonly-encountered parts for us. Moreover, the fields were also largely chosen based on things that we are interested in tracking w/r/t the part properties (manufacturer information and footprint/schematic symbol information notwithstanding). Right now, the fields and tables are pretty tightly coupled with the code, so adding/removing tables and changing fields is non-trivial, but this is a known limitation and should be fixed in a future release.

Setup is fairly simple and much is documented in the [MariaDB Knowledge Base](https://mariadb.com/kb/en/). First steps are simply getting a MariaDB instance up and running, including the driver for connecting over ODBC:
* [Setup MariaDB](https://mariadb.com/kb/en/mariadb/getting-installing-and-upgrading-mariadb/)
* [Install the MariaDB Connector for ODBC](https://mariadb.com/kb/en/mariadb/about-mariadb-connector-j/)
    * Set up the database as a DSN datasource in `odbcad32.exe` on Windows

Currently, the front-end expects a user named "parts_db_editor". How you create this user is up to you, but __right now the front-end doesn't provide authentication for this password-less user so use caution__. Consider limiting the hosts that can connect to the database. Currently this is targeted for a future release.

Once the MariaDB instance is created, setup the parts database by opening the mysql shell and typing:
`source [path-to-PartsTablesSchema.sql]`
to create the tables and grant permissions to the "parts_db_editor" user.

If the database is available, you should be able to input the hostname/IP for the machine hosting the database and connect using the Database>Connect dialog in the main front-end GUI.
___

 



