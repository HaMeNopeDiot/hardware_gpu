from jinja2 import Environment, FileSystemLoader

THREAD_CNT  = 4
FREESPACE   = 20

reg_names = [
    {"name": "CORE CTRL", "cnt" : 1, "cnt_name": None        },
    {"name": "PC"       , "cnt" : 1, "cnt_name": None        },
    {"name": "TU EN"    , "cnt" : 1, "cnt_name": None        },
    {"name": "VID"      , "cnt" : 4, "cnt_name": "THREAD_CNT"}
]

regs = []
for r in reg_names:
    r_name = r.get("name")
    var_name = r_name.replace(" ", "_")
    var_uc = var_name.upper()
    var_lc = var_name.lower()

    if r.get("cnt") > 1:
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

res_filename = "csrm_result.sv"
res_context = {"regs": regs, "free_common_space": FREESPACE * " "}


with open(res_filename, mode="w", encoding="utf-8") as results:
    results.write(template.render(res_context))
    print(f"... wrote {res_filename}")