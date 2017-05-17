# Front-end for Altium Designer Parts DB
---

This program serves as a front-end for an internal Altium Designer database library (.DBLib) and connects to a locally-hosted MariaDB instance to store part data. The program was built in QtCreator and compiled with Qt 5.8, but I didn't stray too far from the basics so I believe it should compile with Qt 5.X and potentially Qt 4.X (though I don't have access to Qt4 on my work machine).

The DatabaseInfo directory contains the schema for building the proper tables within the database as well as some information for getting it setup and pointing the front-end to it. Right now, it uses the ODBC driver and MariaDB connector, but it *should* be compatible with any SQL-based database with minimal modification.

Footprint and Symbol information are parsed from the actual Altium library files (.PcbLib and .SchLib, respectively) using [another small utility I wrote](https://github.com/fierst/AltiumLibParser).

___

Initially, the motivation was building something that maintained Vault-like functionality with regards to the manufacturers list, which is not natively provided in Altium Designer. The branch 'mfg_info' allows for input of up to 15 manufacturers with fields for datasheets/compliance information, part status (active/inactive), etc. We switched to using [Ciiva](https://ciiva.com) to maintain this information, so this branch works but likely won't see much usage for us.

___

Right now, it works and serves its purpose, but there are many areas that need to be addressed and very likely some bugs that I haven't encountered yet. I'll try to keep track of them in the issue tracker, but feel free to submit issues when you encounter things or pull-requests if you feel like modifying the code. 
 



