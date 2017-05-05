#ifndef DB_DEFINES_H
#define DB_DEFINES_H

#include <QList>
#include <QString>

// TODO: Query these from the database instead of hard-coding them.

static const QList<QString> db_base_params ({   "description",
                                                "footprint_ref",
                                                "footprint_path",
                                                "library_ref",
                                                "library_path"});

static const QList<QString> db_capacitor_params ({   "capacitance",
                                        "tolerance",
                                        "voltage",
                                        "temperature_coefficient"});


static const QList<QString> db_connector_params ({   "number_of_positions",
                                        "number_of_rows",
                                        "contact_finish",
                                        "current",
                                        "voltage",
                                        "wire_gauge"});


static const QList<QString> db_diode_params ({       "type",
                                        "current_reverse",
                                        "voltage_forward",
                                        "voltage_zener",
                                        "tolerance",
                                        "power_max",
                                        "impedance_max",
                                        "capacitance",
                                        "reverse_recovery_time"});


static const QList<QString> db_electromechanical_params ({   "type",
                                                "current_rating",
                                                "voltage_rating",
                                                "on_state_resistance",
                                                "voltage_input",
                                                "voltage_load",
                                                "circuit",
                                                "coil_type",
                                                "coil_current",
                                                "coil_voltage",
                                                "voltage_on",
                                                "voltage_off",
                                                "operating_time",
                                                "release_time"});


static const QList<QString> db_filter_params ({  "filter_type",
                                    "impedance",
                                    "inductance",
                                    "bandwidth",
                                    "frequency",
                                    "resistance",
                                    "voltage_rating",
                                    "current_rating",
                                    "operating_temperature"});


static const QList<QString> db_fuse_params ({    "fuse_type",
                                    "current_rating",
                                    "response_time",
                                    "voltage_rating_ac",
                                    "voltage_rating_dc",
                                    "breaking_capacity"});


static const QList<QString> db_ic_params ({"operating_temperature"});


static const QList<QString> db_inductor_params ({"inductance",
                                    "tolerance",
                                    "core_material",
                                    "current_rating",
                                    "resistance",
                                    "operating_temperature"});


static const QList<QString> db_mechanical_params ({"mechanical_type"});


static const QList<QString> db_optoelectronic_params ({  "color",
                                            "wavelength",
                                            "power_dissipation",
                                            "voltage_forward",
                                            "current_rating",
                                            "millicandela_rating"});


static const QList<QString> db_oscillator_params ({  "frequency",
                                        "tolerance",
                                        "load_capacitance",
                                        "equivalent_series_resistance",
                                        "voltage",
                                        "current",
                                        "output_type"});


static const QList<QString> db_power_params ({   "type",
                                    "voltage_input_min",
                                    "voltage_input_max",
                                    "voltage_output_1",
                                    "voltage_output_2",
                                    "voltage_output_3",
                                    "number_of_outputs",
                                    "current_output",
                                    "voltage_isolation",
                                    "power",
                                    "efficiency"});


static const QList<QString> db_resistor_params ({"resistance",
                                    "tolerance",
                                    "power",
                                    "operating_temperature",
                                    "temperature_coefficient"});


static const QList<QString> db_transformer_params ({ "transformer_type",
                                        "voltage_primary",
                                        "voltage_secondary",
                                        "center_tap",
                                        "power_max",
                                        "current_output",
                                        "voltage_isolation",
                                        "inductance",
                                        "turns_ratio"});


static const QList<QString> db_transistor_params ({  "transistor_type",
                                        "power_max",
                                        "operating_temperature",
                                        "current_collector",
                                        "vce_breakdown",
                                        "vce_saturation",
                                        "dc_current_gain",
                                        "current_drain",
                                        "vdss",
                                        "drive_voltage",
                                        "vgs",
                                        "rds_on"});

static const std::map<QString, QList<QString>> table_params_map {{ QString("Capacitor"), db_capacitor_params },
                                                                 { QString("Connector"), db_connector_params },
                                                                 { QString("Diode"), db_diode_params },
                                                                 { QString("Electromechanical"), db_electromechanical_params },
                                                                 { QString("Filter"), db_filter_params },
                                                                 { QString("Fuse"), db_fuse_params },
                                                                 { QString("IC"), db_ic_params },
                                                                 { QString("Inductor"), db_inductor_params },
                                                                 { QString("Mechanical"), db_mechanical_params },
                                                                 { QString("Optoelectronic"), db_optoelectronic_params },
                                                                 { QString("Oscillator"), db_oscillator_params },
                                                                 { QString("Power"), db_power_params },
                                                                 { QString("Resistor"), db_resistor_params },
                                                                 { QString("Transformer"), db_transformer_params },
                                                                 { QString("Transistor"), db_transistor_params }};
#endif // DB_DEFINES_H
