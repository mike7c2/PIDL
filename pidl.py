import pidl_cgen
import pidl_schema
import argparse

if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="RIDL Parser and generator"
    )
    parser.add_argument('file', action='store', type=str, help='RIDL file to parse')
    parser.add_argument('-c', '--generate-c', help="Enable generation of C", action="store_true")
    args = parser.parse_args()

    parsed_device = pidl_schema.parse_pidl(args.file)
    if args.generate_c:
        print(pidl_cgen.cgen(parsed_device))