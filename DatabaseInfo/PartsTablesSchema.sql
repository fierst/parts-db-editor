/* Create the database */
CREATE DATABASE IF NOT EXISTS parts;

/* Switch to that databse */
USE parts;

/* Create table for each class of parts */
CREATE TABLE IF NOT EXISTS Capacitor (
  part_number VARCHAR(12) NOT NULL PRIMARY KEY DEFAULT '',
  description VARCHAR(255),
  capacitance VARCHAR(32),
  tolerance VARCHAR(32),
  voltage VARCHAR(32),
  temperature_coefficient VARCHAR(32),
  footprint_ref VARCHAR(32) NOT NULL,
  footprint_path VARCHAR(2555) NOT NULL,
  library_ref VARCHAR(32) NOT NULL,
  library_path VARCHAR(2555) NOT NULL
);

CREATE TABLE IF NOT EXISTS Connector (
  part_number VARCHAR(12) NOT NULL PRIMARY KEY DEFAULT '',
  description VARCHAR(255),
  number_of_positions VARCHAR(32),
  number_of_rows VARCHAR(32),
  contact_finish VARCHAR(32),
  current VARCHAR(32),
  voltage VARCHAR(32),
  wire_gauge VARCHAR(32),
  footprint_ref VARCHAR(32) NOT NULL,
  footprint_path VARCHAR(255) NOT NULL,
  library_ref VARCHAR(32) NOT NULL,
  library_path VARCHAR(255) NOT NULL
);

CREATE TABLE IF NOT EXISTS Diode (
  part_number VARCHAR(12) NOT NULL PRIMARY KEY DEFAULT '',
  description VARCHAR(255),
  type VARCHAR(32),
  current_reverse VARCHAR(32),
  voltage_forward VARCHAR(32),
  voltage_zener VARCHAR(32),
  tolerance VARCHAR(32),
  power_max VARCHAR(32),
  impedance_max VARCHAR(32),
  capacitance VARCHAR(32),
  reverse_recovery_time VARCHAR(32),
  footprint_ref VARCHAR(32) NOT NULL,
  footprint_path VARCHAR(255) NOT NULL,
  library_ref VARCHAR(32) NOT NULL,
  library_path VARCHAR(255) NOT NULL
);

CREATE TABLE IF NOT EXISTS Electromechanical (
  part_number VARCHAR(12) NOT NULL PRIMARY KEY DEFAULT '',
  description VARCHAR(255),
  type VARCHAR(32),
  current_rating VARCHAR(32),
  voltage_rating VARCHAR(32),
  on_state_resistance VARCHAR(32),
  voltage_input VARCHAR(32),
  voltage_load VARCHAR(32),
  circuit VARCHAR(32),
  coil_type VARCHAR(32),
  coil_current VARCHAR(32),
  coil_voltage VARCHAR(32),
  voltage_on VARCHAR(32),
  voltage_off VARCHAR(32),
  operating_time VARCHAR(32),
  release_time VARCHAR(32),
  footprint_ref VARCHAR(32) NOT NULL,
  footprint_path VARCHAR(255) NOT NULL,
  library_ref VARCHAR(32) NOT NULL,
  library_path VARCHAR(255) NOT NULL
);

CREATE TABLE IF NOT EXISTS Filter (
  part_number VARCHAR(12) NOT NULL PRIMARY KEY DEFAULT '',
  description VARCHAR(255),
  filter_type VARCHAR(32),
  impedance VARCHAR(32),
  inductance VARCHAR(32),
  bandwidth VARCHAR(32),
  frequency VARCHAR(32),
  resistance VARCHAR(32),
  voltage_rating VARCHAR(32),
  current_rating VARCHAR(32),
  operating_temperature VARCHAR(32),
  footprint_ref VARCHAR(32) NOT NULL,
  footprint_path VARCHAR(255) NOT NULL,
  library_ref VARCHAR(32) NOT NULL,
  library_path VARCHAR(255) NOT NULL
);

CREATE TABLE IF NOT EXISTS Fuse (
  part_number VARCHAR(12) NOT NULL PRIMARY KEY DEFAULT '',
  description VARCHAR(255),
  fuse_type VARCHAR(32),
  current_rating VARCHAR(32),
  response_time VARCHAR(32),
  voltage_rating_ac VARCHAR(32),
  voltage_rating_dc VARCHAR(32),
  breaking_capacity VARCHAR(32),
  footprint_ref VARCHAR(32) NOT NULL,
  footprint_path VARCHAR(255) NOT NULL,
  library_ref VARCHAR(32) NOT NULL,
  library_path VARCHAR(255) NOT NULL
);

CREATE TABLE IF NOT EXISTS IC (
  part_number VARCHAR(12) NOT NULL PRIMARY KEY DEFAULT '',
  description VARCHAR(255),
  operating_temperature VARCHAR(32),
  footprint_ref VARCHAR(32) NOT NULL,
  footprint_path VARCHAR(255) NOT NULL,
  library_ref VARCHAR(32) NOT NULL,
  library_path VARCHAR(255) NOT NULL
);

CREATE TABLE IF NOT EXISTS Inductor (
  part_number VARCHAR(12) NOT NULL PRIMARY KEY DEFAULT '',
  description VARCHAR(255),
  inductance VARCHAR(32),
  tolerance VARCHAR(32),
  core_material VARCHAR(32),
  current_rating VARCHAR(32),
  resistance VARCHAR(32),
  operating_temperature VARCHAR(32),
  footprint_ref VARCHAR(32) NOT NULL,
  footprint_path VARCHAR(255) NOT NULL,
  library_ref VARCHAR(32) NOT NULL,
  library_path VARCHAR(255) NOT NULL
);

CREATE TABLE IF NOT EXISTS Mechanical (
  part_number VARCHAR(12) NOT NULL PRIMARY KEY DEFAULT '',
  description VARCHAR(255),
  mechanical_type VARCHAR(32),
  footprint_ref VARCHAR(32) NOT NULL,
  footprint_path VARCHAR(255) NOT NULL,
  library_ref VARCHAR(32) NOT NULL,
  library_path VARCHAR(255) NOT NULL
);

CREATE TABLE IF NOT EXISTS Optoelectronic (
  part_number VARCHAR(12) NOT NULL PRIMARY KEY DEFAULT '',
  description VARCHAR(255),
  color VARCHAR(32),
  wavelength VARCHAR(32),
  power_dissipation VARCHAR(32),
  voltage_forward VARCHAR(32),
  current_rating VARCHAR(32),
  millicandela_rating VARCHAR(32),
  footprint_ref VARCHAR(32) NOT NULL,
  footprint_path VARCHAR(255) NOT NULL,
  library_ref VARCHAR(32) NOT NULL,
  library_path VARCHAR(255) NOT NULL
);

CREATE TABLE IF NOT EXISTS Oscillator (
  part_number VARCHAR(12) NOT NULL PRIMARY KEY DEFAULT '',
  description VARCHAR(255),
  frequency VARCHAR(32),
  tolerance VARCHAR(32),
  load_capacitance VARCHAR(32),
  equivalent_series_resistance VARCHAR(32),
  voltage VARCHAR(32),
  current VARCHAR(32),
  output_type VARCHAR(32),
  footprint_ref VARCHAR(32) NOT NULL,
  footprint_path VARCHAR(255) NOT NULL,
  library_ref VARCHAR(32) NOT NULL,
  library_path VARCHAR(255) NOT NULL
);

CREATE TABLE IF NOT EXISTS Power (
  part_number VARCHAR(12) NOT NULL PRIMARY KEY DEFAULT '',
  description VARCHAR(255),
  type VARCHAR(32),
  voltage_input_min VARCHAR(32),
  voltage_input_max VARCHAR(32),
  voltage_output_1 VARCHAR(32),
  voltage_output_2 VARCHAR(32),
  voltage_output_3 VARCHAR(32),
  number_of_outputs VARCHAR(32),
  current_output VARCHAR(32),
  voltage_isolation VARCHAR(32),
  power VARCHAR(32),
  efficiency VARCHAR(32),
  footprint_ref VARCHAR(32) NOT NULL,
  footprint_path VARCHAR(255) NOT NULL,
  library_ref VARCHAR(32) NOT NULL,
  library_path VARCHAR(255) NOT NULL
);

CREATE TABLE IF NOT EXISTS Resistor (
  part_number VARCHAR(12) NOT NULL PRIMARY KEY DEFAULT '',
  description VARCHAR(255),
  resistance VARCHAR(32),
  tolerance VARCHAR(32),
  power VARCHAR(32),
  operating_temperature VARCHAR(32),
  temperature_coefficient VARCHAR(32),
  footprint_ref VARCHAR(32) NOT NULL,
  footprint_path VARCHAR(255) NOT NULL,
  library_ref VARCHAR(32) NOT NULL,
  library_path VARCHAR(255) NOT NULL
);

CREATE TABLE IF NOT EXISTS Transformer (
  part_number VARCHAR(12) NOT NULL PRIMARY KEY DEFAULT '',
  description VARCHAR(255),
  transformer_type VARCHAR(32),
  voltage_primary VARCHAR(32),
  voltage_secondary VARCHAR(32),
  center_tap BOOLEAN,
  power_max VARCHAR(32),
  current_output VARCHAR(32),
  voltage_isolation VARCHAR(32),
  inductance VARCHAR(32),
  turns_ratio VARCHAR(32),
  footprint_ref VARCHAR(32) NOT NULL,
  footprint_path VARCHAR(255) NOT NULL,
  library_ref VARCHAR(32) NOT NULL,
  library_path VARCHAR(255) NOT NULL
);

CREATE TABLE IF NOT EXISTS Transistor (
  part_number VARCHAR(12) NOT NULL PRIMARY KEY DEFAULT '',
  description VARCHAR(255),
  transistor_type VARCHAR(32),
  power_max VARCHAR(32),
  operating_temperature VARCHAR(32),
  current_collector VARCHAR(32),
  vce_breakdown VARCHAR(32),
  vce_saturation VARCHAR(32),
  dc_current_gain VARCHAR(32),
  current_drain VARCHAR(32),
  vdss VARCHAR(32),
  drive_voltage VARCHAR(32),
  vgs VARCHAR(32),
  rds_on VARCHAR(32),
  footprint_ref VARCHAR(32) NOT NULL,
  footprint_path VARCHAR(255) NOT NULL,
  library_ref VARCHAR(32) NOT NULL,
  library_path VARCHAR(255) NOT NULL
);

CREATE TABLE IF NOT EXISTS Capacitor_id
(
  id INT NOT NULL AUTO_INCREMENT PRIMARY KEY
);

DELIMITER $$
CREATE TRIGGER tg_bi_Capacitor_id
BEFORE INSERT ON Capacitor
FOR EACH ROW 
BEGIN
  INSERT INTO Capacitor_id() VALUES();
  SET NEW.part_number = CONCAT('CAP-', LPAD(LAST_INSERT_ID(), 8, '0'));
END$$
DELIMITER ;

CREATE TABLE IF NOT EXISTS Connector_id
(
  id INT NOT NULL AUTO_INCREMENT PRIMARY KEY
);

DELIMITER $$
CREATE TRIGGER tg_bi_Connector_id
BEFORE INSERT ON Connector
FOR EACH ROW 
BEGIN
  INSERT INTO Connector_id() VALUES();
  SET NEW.part_number = CONCAT('CON-', LPAD(LAST_INSERT_ID(), 8, '0'));
END$$
DELIMITER ;

CREATE TABLE IF NOT EXISTS Diode_id
(
  id INT NOT NULL AUTO_INCREMENT PRIMARY KEY
);

DELIMITER $$
CREATE TRIGGER tg_bi_Diode_id
BEFORE INSERT ON Diode
FOR EACH ROW 
BEGIN
  INSERT INTO Diode_id() VALUES();
  SET NEW.part_number = CONCAT('DIO-', LPAD(LAST_INSERT_ID(), 8, '0'));
END$$
DELIMITER ;

CREATE TABLE IF NOT EXISTS Electromechanical_id
(
  id INT NOT NULL AUTO_INCREMENT PRIMARY KEY
);

DELIMITER $$
CREATE TRIGGER tg_bi_Electromechanical_id
BEFORE INSERT ON Electromechanical
FOR EACH ROW 
BEGIN
  INSERT INTO Electromechanical_id() VALUES();
  SET NEW.part_number = CONCAT('EMC-', LPAD(LAST_INSERT_ID(), 8, '0'));
END$$
DELIMITER ;

CREATE TABLE IF NOT EXISTS Filter_id
(
  id INT NOT NULL AUTO_INCREMENT PRIMARY KEY
);

DELIMITER $$
CREATE TRIGGER tg_bi_Filter_id
BEFORE INSERT ON Filter
FOR EACH ROW 
BEGIN
  INSERT INTO Filter_id() VALUES();
  SET NEW.part_number = CONCAT('FIL-', LPAD(LAST_INSERT_ID(), 8, '0'));
END$$
DELIMITER ;

CREATE TABLE IF NOT EXISTS Fuse_id
(
  id INT NOT NULL AUTO_INCREMENT PRIMARY KEY
);

DELIMITER $$
CREATE TRIGGER tg_bi_Fuse_id
BEFORE INSERT ON Fuse
FOR EACH ROW 
BEGIN
  INSERT INTO Fuse_id() VALUES();
  SET NEW.part_number = CONCAT('FUS-', LPAD(LAST_INSERT_ID(), 8, '0'));
END$$
DELIMITER ;

CREATE TABLE IF NOT EXISTS IC_id
(
  id INT NOT NULL AUTO_INCREMENT PRIMARY KEY
);

DELIMITER $$
CREATE TRIGGER tg_bi_IC_id
BEFORE INSERT ON IC
FOR EACH ROW 
BEGIN
  INSERT INTO IC_id() VALUES();
  SET NEW.part_number = CONCAT('IC-', LPAD(LAST_INSERT_ID(), 8, '0'));
END$$
DELIMITER ;

CREATE TABLE IF NOT EXISTS Inductor_id
(
  id INT NOT NULL AUTO_INCREMENT PRIMARY KEY
);

DELIMITER $$
CREATE TRIGGER tg_bi_Inductor_id
BEFORE INSERT ON Inductor
FOR EACH ROW 
BEGIN
  INSERT INTO Inductor_id() VALUES();
  SET NEW.part_number = CONCAT('IND-', LPAD(LAST_INSERT_ID(), 8, '0'));
END$$
DELIMITER ;

CREATE TABLE IF NOT EXISTS Mechanical_id
(
  id INT NOT NULL AUTO_INCREMENT PRIMARY KEY
);

DELIMITER $$
CREATE TRIGGER tg_bi_Mechanical_id
BEFORE INSERT ON Mechanical
FOR EACH ROW 
BEGIN
  INSERT INTO Mechanical_id() VALUES();
  SET NEW.part_number = CONCAT('MEC-', LPAD(LAST_INSERT_ID(), 8, '0'));
END$$
DELIMITER ;

CREATE TABLE IF NOT EXISTS Optoelectronic_id
(
  id INT NOT NULL AUTO_INCREMENT PRIMARY KEY
);

DELIMITER $$
CREATE TRIGGER tg_bi_Optoelectronic_id
BEFORE INSERT ON Optoelectronic
FOR EACH ROW 
BEGIN
  INSERT INTO Optoelectronic_id() VALUES();
  SET NEW.part_number = CONCAT('OPT-', LPAD(LAST_INSERT_ID(), 8, '0'));
END$$
DELIMITER ;

CREATE TABLE IF NOT EXISTS Oscillator_id
(
  id INT NOT NULL AUTO_INCREMENT PRIMARY KEY
);

DELIMITER $$
CREATE TRIGGER tg_bi_Oscillator_id
BEFORE INSERT ON Oscillator
FOR EACH ROW 
BEGIN
  INSERT INTO Oscillator_id() VALUES();
  SET NEW.part_number = CONCAT('OSC-', LPAD(LAST_INSERT_ID(), 8, '0'));
END$$
DELIMITER ;

CREATE TABLE IF NOT EXISTS Power_id
(
  id INT NOT NULL AUTO_INCREMENT PRIMARY KEY
);

DELIMITER $$
CREATE TRIGger tg_bi_Power_id
BEFORE INSERT ON Power
FOR EACH ROW 
BEGIN
  INSERT INTO Power_id() VALUES();
  SET NEW.part_number = CONCAT('POW-', LPAD(LAST_INSERT_ID(), 8, '0'));
END$$
DELIMITER ;

CREATE TABLE IF NOT EXISTS Resistor_id
(
  id INT NOT NULL AUTO_INCREMENT PRIMARY KEY
);

DELIMITER $$
CREATE TRIGGER tg_bi_Resistor_id
BEFORE INSERT ON Resistor
FOR EACH ROW 
BEGIN
  INSERT INTO Resistor_id() VALUES();
  SET NEW.part_number = CONCAT('RES-', LPAD(LAST_INSERT_ID(), 8, '0'));
END$$
DELIMITER ;

CREATE TABLE IF NOT EXISTS Transformer_id
(
  id INT NOT NULL AUTO_INCREMENT PRIMARY KEY
);

DELIMITER $$
CREATE TRIGGER tg_bi_Transformer_id
BEFORE INSERT ON Transformer
FOR EACH ROW 
BEGIN
  INSERT INTO Transformer_id() VALUES();
  SET NEW.part_number = CONCAT('XFR-', LPAD(LAST_INSERT_ID(), 8, '0'));
END$$
DELIMITER ;

CREATE TABLE IF NOT EXISTS Transistor_id
(
  id INT NOT NULL AUTO_INCREMENT PRIMARY KEY
);

DELIMITER $$
CREATE TRIGGER tg_bi_Transistor_id
BEFORE INSERT ON Transistor
FOR EACH ROW 
BEGIN
  INSERT INTO Transistor_id() VALUES();
  SET NEW.part_number = CONCAT('TRN-', LPAD(LAST_INSERT_ID(), 8, '0'));
END$$
DELIMITER ;


/* REQUIRES USER NAMED 'parts_db_editor', make sure this user exists */

/* Grant proper privileges to the altium_db_editor user for each table */
/* Do each table explicitly because it's not farfetched to think a user already has a db named 'parts' with other stuff in it...*/
GRANT INSERT, SELECT, UPDATE ON parts.Capacitor TO 'parts_db_editor';
GRANT INSERT, SELECT, UPDATE ON parts.Connector TO 'parts_db_editor';
GRANT INSERT, SELECT, UPDATE ON parts.Diode TO 'parts_db_editor';
GRANT INSERT, SELECT, UPDATE ON parts.Electromechanical TO 'parts_db_editor';
GRANT INSERT, SELECT, UPDATE ON parts.Filter TO 'parts_db_editor';
GRANT INSERT, SELECT, UPDATE ON parts.Fuse TO 'parts_db_editor';
GRANT INSERT, SELECT, UPDATE ON parts.IC TO 'parts_db_editor';
GRANT INSERT, SELECT, UPDATE ON parts.Inductor TO 'parts_db_editor';
GRANT INSERT, SELECT, UPDATE ON parts.Mechanical TO 'parts_db_editor';
GRANT INSERT, SELECT, UPDATE ON parts.Optoelectronic TO 'parts_db_editor';
GRANT INSERT, SELECT, UPDATE ON parts.Oscillator TO 'parts_db_editor';
GRANT INSERT, SELECT, UPDATE ON parts.Power TO 'parts_db_editor';
GRANT INSERT, SELECT, UPDATE ON parts.Resistor TO 'parts_db_editor';
GRANT INSERT, SELECT, UPDATE ON parts.Transformer TO 'parts_db_editor';
GRANT INSERT, SELECT, UPDATE ON parts.Transistor TO 'parts_db_editor';