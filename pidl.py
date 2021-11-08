import pidl_cgen
import pidl_schema
import argparse
import os
import glob

if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="RIDL Parser and generator"
    )
    parser.add_argument('--file', action='store', type=str, help='RIDL file to parse')
    parser.add_argument('--in-dir', action='store', type=str, help='Folder of devices to parse')
    parser.add_argument('--out-dir', action='store', type=str, help='OUtput folder')
    parser.add_argument('-c', '--generate-c', help="Enable generation of C", action="store_true")
    args = parser.parse_args()

    if args.file:
        parsed_device = pidl_schema.parse_pidl(args.file)
        if args.generate_c:
            print(pidl_cgen.cgen(parsed_device))
    
    if args.in_dir:
        if args.out_dir:
            out_dir = args.out_dir
        else:
            out_dir = ""
        for f in glob.glob(os.path.join(args.in_dir, "*.pidl")):
            name = os.path.split(f)[-1].split(".")[0]
            outname = os.path.join(out_dir, name+".h")
            print("Processing %s to %s" % (f, outname))
            parsed_device = pidl_schema.parse_pidl(f)
            open(outname, "w").write(pidl_cgen.cgen(parsed_device))