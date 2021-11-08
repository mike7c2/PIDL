from jinja2 import Template
import pidl_schema

C_HEADER_TEMPLATE = Template("""/**
 * Automatically generated code by pidl
 * Definition generated using:
 *     {{datasheet_link}}
 *     {{datasheet_title}}
 *     {{datasheet_revision}}
 */
/**
 * This is a set of register definitions for {{ device_name }}
 *
{{ device_description }}*/""")

C_REGISTER_TEMPLATE = Template("""
/**
 * Definitions for {{ register_name }} register
 *
{{register_description}}
*/
#define {{ register_define }}""")

C_FIELD_TEMPLATE = Template("""
/* {{ field_description }} */
#define {{ field_define }}_Pos {{ field_position }}
#define {{ field_define }}_Msk ({{ field_mask }} << {{ field_define }}_Pos)
#define {{ field_define }} {{ field_define }}_Msk""")

def multiline_comment(text, lim=80):
    lines = []
    c_line = " * "
    words = text.split(" ")

    for w in words:
        if len(w.strip()) <= 0:
            continue
        if len(c_line + w) > lim:
            lines.append(c_line)
            c_line = " * " + w + " "
        else:
            c_line += w + " "
    lines.append(c_line)
    return "\n".join(lines)

def cgen(device):
    header_text = ""
    header_content = {
        "device_name": device.name.upper(),
        "device_description": multiline_comment(device.description),
        "datasheet_link": device.datasheet["link"],
        "datasheet_title": device.datasheet["title"],
        "datasheet_revision": device.datasheet["revision"],
    }
    header_text += C_HEADER_TEMPLATE.render(header_content)
    header_text += "\n"
    header_text += "#ifndef " + header_content["device_name"] + "_H\n#define " + header_content["device_name"] + "_H\n"

    for r in device.registers:
        register_content = {
            "register_name": r.name,
            "register_description": multiline_comment(r.description),
            "register_define": device.name.upper() + "_" + r.name.upper().replace(" ", "_") + "_" + "INDEX" + " " + str(r.offset)
        }

        header_text += C_REGISTER_TEMPLATE.render(register_content)
        header_text += "\n"
        # Don't output field templates when entire register is single field
        if (len(r.fields) == 1) and (r.fields[0].bitRange.width() == r.size):
            continue
        for f in r.fields:
            field_content = {
                "field_description": f.description,
                "field_position": "(%d)" % f.bitRange.stop,
                "field_mask": "(" + hex(2 ** ((f.bitRange.start+1) - f.bitRange.stop)-1) + ")",
                "field_define": device.name.upper() + "_" + r.name.upper().replace(" ", "_") + "_" + f.name.upper()
            }

            header_text += C_FIELD_TEMPLATE.render(field_content) + "\n"
            for e in f.enumeratedValues:
                header_text += "#define " + field_content["field_define"] + "_" + e.name.upper() + " " + \
                               "(" + str(e.value) + " << " + field_content["field_define"] + "_Pos)" + "        " + \
                               "/* " + e.description + "*/\n"
    header_text += "\n#endif"
    return header_text