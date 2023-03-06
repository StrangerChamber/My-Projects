 var codasip_asips_data = {
"information" : {
"ide_version": "9.1.1-1255",
"project_name": "cu_riscv32i_cycle_accurate",
"date": "2022-12-07 23:50:27"
},
"PerUnit" : [
{
"unit": "Global Resources",
"detail": [{"count": 1,
"bitwidth": 32,
"type": "Register File",
"detail": "size: 32, data ports: read 2x, write 1x"
},
{"count": 3,
"bitwidth": 1,
"type": "Register",
"detail": ""
},
{"count": 3,
"bitwidth": 32,
"type": "Register",
"detail": ""
},
{"count": 1,
"bitwidth": 2,
"type": "Register",
"detail": ""
},
{"count": 14,
"bitwidth": 1,
"type": "Pipeline Register",
"detail": ""
},
{"count": 10,
"bitwidth": 32,
"type": "Pipeline Register",
"detail": ""
},
{"count": 6,
"bitwidth": 5,
"type": "Pipeline Register",
"detail": ""
},
{"count": 4,
"bitwidth": 2,
"type": "Pipeline Register",
"detail": ""
},
{"count": 2,
"bitwidth": 4,
"type": "Pipeline Register",
"detail": ""
}
]
},
{
"unit": "alu_operate",
"detail": [{"count": 2,
"bitwidth": 32,
"type": "Adder",
"detail": ""
},
{"count": 4,
"bitwidth": 32,
"type": "Comparator",
"detail": "operator: <"
},
{"count": 1,
"bitwidth": 32,
"type": "Logical Shift Left",
"detail": ""
},
{"count": 1,
"bitwidth": 32,
"type": "Logical Shift Right",
"detail": ""
},
{"count": 1,
"bitwidth": 32,
"type": "Arithmetic Shift Left",
"detail": ""
},
{"count": 2,
"bitwidth": 32,
"type": "Arithmetic Shift Right",
"detail": ""
},
{"count": 5,
"bitwidth": 1,
"type": "Multiplexer",
"detail": "inputs: 2"
},
{"count": 2,
"bitwidth": 32,
"type": "Multiplexer",
"detail": "inputs: 2"
},
{"count": 1,
"bitwidth": 32,
"type": "Multiplexer",
"detail": "inputs: 19"
}
]
},
{
"unit": "branch_logic",
"detail": [{"count": 1,
"bitwidth": 1,
"type": "Multiplexer",
"detail": "inputs: 5"
},
{"count": 1,
"bitwidth": 1,
"type": "Multiplexer",
"detail": "inputs: 2"
}
]
},
{
"unit": "ex",
"detail": [{"count": 2,
"bitwidth": 32,
"type": "Adder",
"detail": ""
},
{"count": 4,
"bitwidth": 5,
"type": "Comparator",
"detail": "operator: =="
},
{"count": 3,
"bitwidth": 32,
"type": "Multiplexer",
"detail": "inputs: 4"
},
{"count": 2,
"bitwidth": 1,
"type": "Multiplexer",
"detail": "inputs: 2"
},
{"count": 2,
"bitwidth": 2,
"type": "Multiplexer",
"detail": "inputs: 3"
},
{"count": 1,
"bitwidth": 32,
"type": "Multiplexer",
"detail": "inputs: 2"
}
]
},
{
"unit": "fe",
"detail": [{"count": 1,
"bitwidth": 32,
"type": "Multiplexer",
"detail": "inputs: 2"
}
]
},
{
"unit": "id",
"detail": [{"count": 4,
"bitwidth": 5,
"type": "Comparator",
"detail": "operator: =="
},
{"count": 4,
"bitwidth": 1,
"type": "Multiplexer",
"detail": "inputs: 2"
},
{"count": 3,
"bitwidth": 32,
"type": "Multiplexer",
"detail": "inputs: 2"
},
{"count": 1,
"bitwidth": 32,
"type": "Multiplexer",
"detail": "inputs: 4"
}
]
},
{
"unit": "id_output",
"detail": [{"count": 1,
"bitwidth": 1,
"type": "Multiplexer",
"detail": "inputs: 2"
},
{"count": 1,
"bitwidth": 32,
"type": "Multiplexer",
"detail": "inputs: 7"
}
]
},
{
"unit": "if_output",
"detail": [{"count": 2,
"bitwidth": 32,
"type": "Adder",
"detail": ""
},
{"count": 2,
"bitwidth": 32,
"type": "Multiplexer",
"detail": "inputs: 2"
}
]
},
{
"unit": "inst_decode",
"detail": [{"count": 1,
"bitwidth": 2,
"type": "Multiplexer",
"detail": "inputs: 3"
},
{"count": 1,
"bitwidth": 4,
"type": "Multiplexer",
"detail": "inputs: 4"
},
{"count": 1,
"bitwidth": 4,
"type": "Multiplexer",
"detail": "inputs: 6"
},
{"count": 1,
"bitwidth": 5,
"type": "Multiplexer",
"detail": "inputs: 7"
},
{"count": 1,
"bitwidth": 2,
"type": "Multiplexer",
"detail": "inputs: 7"
},
{"count": 1,
"bitwidth": 5,
"type": "Multiplexer",
"detail": "inputs: 6"
},
{"count": 1,
"bitwidth": 5,
"type": "Multiplexer",
"detail": "inputs: 3"
},
{"count": 1,
"bitwidth": 5,
"type": "Multiplexer",
"detail": "inputs: 10"
}
]
},
{
"unit": "me",
"detail": [{"count": 1,
"bitwidth": 32,
"type": "Logical Shift Right",
"detail": ""
},
{"count": 1,
"bitwidth": 1,
"type": "Multiplexer",
"detail": "inputs: 2"
},
{"count": 1,
"bitwidth": 32,
"type": "Multiplexer",
"detail": "inputs: 6"
}
]
},
{
"unit": "memory_operation",
"detail": [{"count": 1,
"bitwidth": 32,
"type": "Logical Shift Left",
"detail": ""
},
{"count": 2,
"bitwidth": 2,
"type": "Multiplexer",
"detail": "inputs: 9"
},
{"count": 1,
"bitwidth": 1,
"type": "Multiplexer",
"detail": "inputs: 9"
}
]
},
{
"unit": "pipeline_control",
"detail": [{"count": 2,
"bitwidth": 1,
"type": "Multiplexer",
"detail": "inputs: 2"
},
{"count": 1,
"bitwidth": 1,
"type": "Multiplexer",
"detail": "inputs: 4"
}
]
},
{
"unit": "wb",
"detail": [{"count": 2,
"bitwidth": 32,
"type": "Multiplexer",
"detail": "inputs: 2"
}
]
}
]
,
"PerResourceType": [{"count": 1,
"bitwidth": 32,
"type": "Register File",
"detail": "size: 32, data ports: read 2x, write 1x"
},
{"count": 3,
"bitwidth": 1,
"type": "Register",
"detail": ""
},
{"count": 3,
"bitwidth": 32,
"type": "Register",
"detail": ""
},
{"count": 1,
"bitwidth": 2,
"type": "Register",
"detail": ""
},
{"count": 14,
"bitwidth": 1,
"type": "Pipeline Register",
"detail": ""
},
{"count": 10,
"bitwidth": 32,
"type": "Pipeline Register",
"detail": ""
},
{"count": 6,
"bitwidth": 5,
"type": "Pipeline Register",
"detail": ""
},
{"count": 4,
"bitwidth": 2,
"type": "Pipeline Register",
"detail": ""
},
{"count": 2,
"bitwidth": 4,
"type": "Pipeline Register",
"detail": ""
},
{"count": 6,
"bitwidth": 32,
"type": "Adder",
"detail": ""
},
{"count": 8,
"bitwidth": 5,
"type": "Comparator",
"detail": "operator: =="
},
{"count": 4,
"bitwidth": 32,
"type": "Comparator",
"detail": "operator: <"
},
{"count": 2,
"bitwidth": 32,
"type": "Logical Shift Left",
"detail": ""
},
{"count": 2,
"bitwidth": 32,
"type": "Logical Shift Right",
"detail": ""
},
{"count": 1,
"bitwidth": 32,
"type": "Arithmetic Shift Left",
"detail": ""
},
{"count": 2,
"bitwidth": 32,
"type": "Arithmetic Shift Right",
"detail": ""
},
{"count": 16,
"bitwidth": 1,
"type": "Multiplexer",
"detail": "inputs: 2"
},
{"count": 11,
"bitwidth": 32,
"type": "Multiplexer",
"detail": "inputs: 2"
},
{"count": 4,
"bitwidth": 32,
"type": "Multiplexer",
"detail": "inputs: 4"
},
{"count": 3,
"bitwidth": 2,
"type": "Multiplexer",
"detail": "inputs: 3"
},
{"count": 2,
"bitwidth": 2,
"type": "Multiplexer",
"detail": "inputs: 9"
},
{"count": 1,
"bitwidth": 1,
"type": "Multiplexer",
"detail": "inputs: 9"
},
{"count": 1,
"bitwidth": 1,
"type": "Multiplexer",
"detail": "inputs: 4"
},
{"count": 1,
"bitwidth": 32,
"type": "Multiplexer",
"detail": "inputs: 6"
},
{"count": 1,
"bitwidth": 5,
"type": "Multiplexer",
"detail": "inputs: 10"
},
{"count": 1,
"bitwidth": 5,
"type": "Multiplexer",
"detail": "inputs: 3"
},
{"count": 1,
"bitwidth": 5,
"type": "Multiplexer",
"detail": "inputs: 6"
},
{"count": 1,
"bitwidth": 2,
"type": "Multiplexer",
"detail": "inputs: 7"
},
{"count": 1,
"bitwidth": 5,
"type": "Multiplexer",
"detail": "inputs: 7"
},
{"count": 1,
"bitwidth": 4,
"type": "Multiplexer",
"detail": "inputs: 6"
},
{"count": 1,
"bitwidth": 4,
"type": "Multiplexer",
"detail": "inputs: 4"
},
{"count": 1,
"bitwidth": 32,
"type": "Multiplexer",
"detail": "inputs: 7"
},
{"count": 1,
"bitwidth": 1,
"type": "Multiplexer",
"detail": "inputs: 5"
},
{"count": 1,
"bitwidth": 32,
"type": "Multiplexer",
"detail": "inputs: 19"
}
],
}
