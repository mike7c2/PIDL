import ridl_cgen
import ridl_schema
import argparse

if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="RIDL Parser and generator"
    )
    parser.add_argument('file', action='store', type=str, help='RIDL file to parse')
    parser.add_argument('-c', '--generate-c', help="Enable generation of C", action="store_true")
    args = parser.parse_args()

    parsed_device = ridl_schema.parse_ridl(args.file)
    if args.generate_c:
        print(ridl_cgen.cgen(parsed_device))