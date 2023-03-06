var codasip_scheduling_data = { 
    "table" : [
        {
            "element" : "alu_operate",
            "instance" : "alu_operate",
            "hdl" : "alu_operate",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 4,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
                { 
                    "id" : "codasip_tmp_var_0",
                    "bits" : 5,
                    "datatype" : "uint5",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                },
                { 
                    "id" : "codasip_tmp_var_1",
                    "bits" : 1,
                    "datatype" : "bool",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                },
                { 
                    "id" : "codasip_tmp_var_2",
                    "bits" : 1,
                    "datatype" : "uint1",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                },
                { 
                    "id" : "codasip_tmp_var_3",
                    "bits" : 1,
                    "datatype" : "uint1",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                }
            ]
        },
        {
            "element" : "inst_decode",
            "instance" : "id.inst_decode",
            "hdl" : "inst_decode",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 1,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
                { 
                    "id" : "INSTRUCTION",
                    "bits" : 17,
                    "datatype" : "uint17",
                    "detail" : "Signal, created during scheduling of the unit automatically by the Codasip framework"
                }
            ]
        },
        {
            "element" : "branch_logic",
            "instance" : "branch_logic",
            "hdl" : "branch_logic",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 2,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
                { 
                    "id" : "codasip_tmp_var_0",
                    "bits" : 2,
                    "datatype" : "uint2",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                },
                { 
                    "id" : "codasip_tmp_var_1",
                    "bits" : 1,
                    "datatype" : "bool",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                }
            ]
        },
        {
            "element" : "i_hw_itype_alu",
            "instance" : "id.inst_decode",
            "hdl" : "i_hw_itype_alu",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 1,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
                { 
                    "id" : "codasip_tmp_var_0",
                    "bits" : 10,
                    "datatype" : "uint10",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                }
            ]
        },
        {
            "element" : "i_hw_rtype_alu",
            "instance" : "id.inst_decode",
            "hdl" : "i_hw_rtype_alu",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 1,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
                { 
                    "id" : "codasip_tmp_var_0",
                    "bits" : 17,
                    "datatype" : "uint17",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                }
            ]
        },
        {
            "element" : "i_hw_utype_ops",
            "instance" : "id.inst_decode",
            "hdl" : "i_hw_utype_ops",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 1,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
                { 
                    "id" : "codasip_tmp_var_0",
                    "bits" : 7,
                    "datatype" : "uint7",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                }
            ]
        },
        {
            "element" : "i_hw_itype_jlreg",
            "instance" : "id.inst_decode",
            "hdl" : "i_hw_itype_jlreg",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "i_hw_itype_loads",
            "instance" : "id.inst_decode",
            "hdl" : "i_hw_itype_loads",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 1,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
                { 
                    "id" : "codasip_tmp_var_0",
                    "bits" : 10,
                    "datatype" : "uint10",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                }
            ]
        },
        {
            "element" : "i_hw_jtype_jlink",
            "instance" : "id.inst_decode",
            "hdl" : "i_hw_jtype_jlink",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "i_hw_rtype_shift",
            "instance" : "id.inst_decode",
            "hdl" : "i_hw_rtype_shift",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 1,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
                { 
                    "id" : "codasip_tmp_var_0",
                    "bits" : 17,
                    "datatype" : "uint17",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                }
            ]
        },
        {
            "element" : "i_hw_stype_store",
            "instance" : "id.inst_decode",
            "hdl" : "i_hw_stype_store",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 1,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
                { 
                    "id" : "codasip_tmp_var_0",
                    "bits" : 10,
                    "datatype" : "uint10",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                }
            ]
        },
        {
            "element" : "memory_operation",
            "instance" : "memory_operation",
            "hdl" : "memory_operation",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 3,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
                { 
                    "id" : "codasip_tmp_var_0",
                    "bits" : 4,
                    "datatype" : "uint4",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                },
                { 
                    "id" : "op_rw",
                    "bits" : 1,
                    "datatype" : "uint1",
                    "detail" : "Signal, created during scheduling of the unit automatically by the Codasip framework"
                },
                { 
                    "id" : "op_type",
                    "bits" : 2,
                    "datatype" : "uint2",
                    "detail" : "Signal, created during scheduling of the unit automatically by the Codasip framework"
                }
            ]
        },
        {
            "element" : "pipeline_control",
            "instance" : "pipeline_control",
            "hdl" : "pipeline_control",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 3,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
                { 
                    "id" : "codasip_tmp_var_0",
                    "bits" : 1,
                    "datatype" : "bool",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                },
                { 
                    "id" : "codasip_tmp_var_1",
                    "bits" : 1,
                    "datatype" : "bool",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                },
                { 
                    "id" : "codasip_tmp_var_2",
                    "bits" : 1,
                    "datatype" : "bool",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                }
            ]
        },
        {
            "element" : "i_hw_btype_branches",
            "instance" : "id.inst_decode",
            "hdl" : "i_hw_btype_branches",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 1,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
                { 
                    "id" : "codasip_tmp_var_0",
                    "bits" : 10,
                    "datatype" : "uint10",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                }
            ]
        },
        {
            "element" : "pma_hprot_inline_1_inline_1",
            "instance" : "",
            "hdl" : "pma_hprot_inline_1_inline_1",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 3,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
                { 
                    "id" : "hprot0_inline_1_inline_1",
                    "bits" : 1,
                    "datatype" : "uint1",
                    "detail" : "Signal, created during scheduling of the unit automatically by the Codasip framework"
                },
                { 
                    "id" : "address_inline_1_inline_1",
                    "bits" : 32,
                    "datatype" : "uint32",
                    "detail" : "Signal, created during scheduling of the unit automatically by the Codasip framework"
                },
                { 
                    "id" : "is_cacheable_bufferable_inline_1_inline_1",
                    "bits" : 1,
                    "datatype" : "uint1",
                    "detail" : "Signal, created during scheduling of the unit automatically by the Codasip framework"
                },
                { 
                    "id" : "codasip_return2_pma_hprot_inline_1_inline_1",
                    "bits" : 4,
                    "datatype" : "uint4",
                    "detail" : "Register, created during scheduling of the unit automatically by the Codasip framework"
                }
            ]
        },
        {
            "element" : "wb",
            "instance" : "wb",
            "hdl" : "wb",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 2,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
                { 
                    "id" : "codasip_tmp_var_0",
                    "bits" : 1,
                    "datatype" : "bool",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                },
                { 
                    "id" : "codasip_tmp_var_1",
                    "bits" : 1,
                    "datatype" : "bool",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                }
            ]
        },
        {
            "element" : "reset",
            "instance" : "",
            "hdl" : "reset",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_lb",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_lb",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_lh",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_lh",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_lw",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_lw",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_or",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_or",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_sb",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_sb",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_sh",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_sh",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_sw",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_sw",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_add",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_add",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_and",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_and",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_beq",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_beq",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_bge",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_bge",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_blt",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_blt",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_bne",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_bne",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_jal",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_jal",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_lbu",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_lbu",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_lhu",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_lhu",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_lui",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_lui",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_ori",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_ori",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_sll",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_sll",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_slt",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_slt",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_sra",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_sra",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_srl",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_srl",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_sub",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_sub",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_xor",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_xor",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_addi",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_addi",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_andi",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_andi",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_bgeu",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_bgeu",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_bltu",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_bltu",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_halt",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_halt",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_jalr",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_jalr",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_slli",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_slli",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_slti",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_slti",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_sltu",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_sltu",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_srai",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_srai",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_srli",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_srli",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_xori",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_xori",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "ex_output",
            "instance" : "ex_output",
            "hdl" : "ex_output",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "i_hw_halt",
            "instance" : "id.inst_decode",
            "hdl" : "i_hw_halt",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "id_output",
            "instance" : "id_output",
            "hdl" : "id_output",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 2,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
                { 
                    "id" : "codasip_tmp_var_0",
                    "bits" : 3,
                    "datatype" : "uint3",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                },
                { 
                    "id" : "codasip_tmp_var_1",
                    "bits" : 1,
                    "datatype" : "bool",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                }
            ]
        },
        {
            "element" : "if_output",
            "instance" : "if_output",
            "hdl" : "if_output",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 1,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
                { 
                    "id" : "codasip_tmp_var_0",
                    "bits" : 1,
                    "datatype" : "bool",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                }
            ]
        },
        {
            "element" : "me_output",
            "instance" : "me_output",
            "hdl" : "me_output",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_auipc",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_auipc",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "opc_sltiu",
            "instance" : "id.inst_decode.opc",
            "hdl" : "opc_sltiu",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        },
        {
            "element" : "ex",
            "instance" : "ex",
            "hdl" : "ex",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 9,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
                { 
                    "id" : "codasip_tmp_var_0",
                    "bits" : 1,
                    "datatype" : "bool",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                },
                { 
                    "id" : "codasip_tmp_var_1",
                    "bits" : 1,
                    "datatype" : "bool",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                },
                { 
                    "id" : "codasip_tmp_var_2",
                    "bits" : 1,
                    "datatype" : "bool",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                },
                { 
                    "id" : "codasip_tmp_var_3",
                    "bits" : 1,
                    "datatype" : "bool",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                },
                { 
                    "id" : "codasip_tmp_var_4",
                    "bits" : 2,
                    "datatype" : "uint2",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                },
                { 
                    "id" : "codasip_tmp_var_5",
                    "bits" : 2,
                    "datatype" : "uint2",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                },
                { 
                    "id" : "codasip_tmp_var_6",
                    "bits" : 2,
                    "datatype" : "uint2",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                },
                { 
                    "id" : "codasip_tmp_var_7",
                    "bits" : 1,
                    "datatype" : "uint1",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                },
                { 
                    "id" : "codasip_tmp_var_8",
                    "bits" : 1,
                    "datatype" : "bool",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                }
            ]
        },
        {
            "element" : "fe",
            "instance" : "fe",
            "hdl" : "fe",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 3,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
                { 
                    "id" : "cache_hprot",
                    "bits" : 4,
                    "datatype" : "uint4",
                    "detail" : "Signal, created during scheduling of the unit automatically by the Codasip framework"
                },
                { 
                    "id" : "codasip_tmp_var_0",
                    "bits" : 1,
                    "datatype" : "bool",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                },
                { 
                    "id" : "if_status",
                    "bits" : 2,
                    "datatype" : "uint2",
                    "detail" : "Signal, created during scheduling of the unit automatically by the Codasip framework"
                }
            ]
        },
        {
            "element" : "id",
            "instance" : "id",
            "hdl" : "id",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 13,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
                { 
                    "id" : "temp_instr",
                    "bits" : 32,
                    "datatype" : "uint32",
                    "detail" : "Signal, created during scheduling of the unit automatically by the Codasip framework"
                },
                { 
                    "id" : "cache_ready",
                    "bits" : 1,
                    "datatype" : "bool",
                    "detail" : "Signal, created during scheduling of the unit automatically by the Codasip framework"
                },
                { 
                    "id" : "id_instr_temp",
                    "bits" : 32,
                    "datatype" : "uint32",
                    "detail" : "Signal, created during scheduling of the unit automatically by the Codasip framework"
                },
                { 
                    "id" : "instr_control",
                    "bits" : 2,
                    "datatype" : "uint2",
                    "detail" : "Signal, created during scheduling of the unit automatically by the Codasip framework"
                },
                { 
                    "id" : "cache_response",
                    "bits" : 1,
                    "datatype" : "bool",
                    "detail" : "Signal, created during scheduling of the unit automatically by the Codasip framework"
                },
                { 
                    "id" : "codasip_tmp_var_0",
                    "bits" : 1,
                    "datatype" : "bool",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                },
                { 
                    "id" : "codasip_tmp_var_1",
                    "bits" : 2,
                    "datatype" : "uint2",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                },
                { 
                    "id" : "codasip_tmp_var_2",
                    "bits" : 1,
                    "datatype" : "bool",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                },
                { 
                    "id" : "codasip_tmp_var_3",
                    "bits" : 1,
                    "datatype" : "bool",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                },
                { 
                    "id" : "codasip_tmp_var_4",
                    "bits" : 1,
                    "datatype" : "bool",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                },
                { 
                    "id" : "codasip_tmp_var_5",
                    "bits" : 1,
                    "datatype" : "uint1",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                },
                { 
                    "id" : "codasip_tmp_var_6",
                    "bits" : 1,
                    "datatype" : "uint1",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                },
                { 
                    "id" : "codasip_tmp_var_7",
                    "bits" : 1,
                    "datatype" : "bool",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                }
            ]
        },
        {
            "element" : "me",
            "instance" : "me",
            "hdl" : "me",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 6,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
                { 
                    "id" : "data_ready",
                    "bits" : 1,
                    "datatype" : "uint1",
                    "detail" : "Signal, created during scheduling of the unit automatically by the Codasip framework"
                },
                { 
                    "id" : "decoded_data",
                    "bits" : 32,
                    "datatype" : "uint32",
                    "detail" : "Signal, created during scheduling of the unit automatically by the Codasip framework"
                },
                { 
                    "id" : "data_response",
                    "bits" : 1,
                    "datatype" : "uint1",
                    "detail" : "Signal, created during scheduling of the unit automatically by the Codasip framework"
                },
                { 
                    "id" : "codasip_tmp_var_0",
                    "bits" : 4,
                    "datatype" : "uint4",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                },
                { 
                    "id" : "codasip_tmp_var_1",
                    "bits" : 1,
                    "datatype" : "bool",
                    "detail" : "Signal, created from condition expressions (if, switch, while, ...) automatically by the Codasip framework"
                },
                { 
                    "id" : "s_ex_load_data_output",
                    "bits" : 32,
                    "datatype" : "uint32",
                    "detail" : "Signal, created during scheduling of the unit automatically by the Codasip framework"
                }
            ]
        },
        {
            "element" : "main",
            "instance" : "",
            "hdl" : "main",
            "numClocks" : {"first" : "0", "second" : "combinatorial logic"},
            "localSignal" : 0,
            "localRegister" : 0,
            "localRegisterFile" : 0,
            "SVGlink" : "",
            "detail" : [
            ]
        }
    ],
    "combinatiorialUnit" : 65,
    "sequentialUnit" : 0,
    "localSignals" : 59,
    "localRegisters" : 0,
    "localRegisterFiles" : 0,
    "svg" : 0
};
