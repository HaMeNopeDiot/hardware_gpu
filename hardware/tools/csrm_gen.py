from datetime import datetime
from jinja2 import Environment, FileSystemLoader

THREAD_CNT  = 4
FREESPACE   = 20

reg_names = [
    {"name": "CORE CTRL", "cnt" : 1},
    {"name": "PC"       , "cnt" : 1},
    {"name": "TU EN"    , "cnt" : 1},
    {"name": "VID"      , "cnt" : 4, "cnt_name": "THREAD_CNT"}
]

regs = []
for r in reg_names:
    r_name = r.get("name")
    var_name = r_name.replace(" ", "_")
    var_uc = var_name.upper()
    var_lc = var_name.lower()

    if "cnt" in r and r.get("cnt") > 1:
        space_pocket_len = (FREESPACE - 5 - len(var_name))
    else:
        space_pocket_len = (FREESPACE - 2 - len(var_name))

    regs.append({"reg_name_uc"      : r_name.upper(),
                 "reg_var_uc"       : var_uc,
                 "reg_var_lc"       : var_lc,
                 "free_space_packet": space_pocket_len * " ",
                 "cnt"              : r.get("cnt"),
                 "cnt_name"         : r.get("cnt_name")
                })

env = Environment(loader=FileSystemLoader("tools/templates/"))
template = env.get_template("reg_inst_template.template")

# for r in regs:
#     print(template.render(r))

parameters = [
    {"name": "AW"       , "type": "int unsigned", "value": 32},
    {"name": "DW"       , "type": "int unsigned", "value": 32},
    {"name": "THREADS"  , "type": "int unsigned", "value": 4}
]

cur_datetime = f"{datetime.today():%Y/%m}"
res_filename = "csrm_result"
res_context  = {"module_name"        : res_filename,
                "desc"               : "Core Control Status Register Map (Core CSRM)",
                "regs"               : regs,
                "free_common_space"  : FREESPACE * " ",
                "parameters"         : parameters,
                "datetime"           : cur_datetime}


with open(res_filename + ".sv", mode="w", encoding="utf-8") as results:
    results.write(template.render(res_context))
    print(f"... wrote {res_filename + ".sv"}")