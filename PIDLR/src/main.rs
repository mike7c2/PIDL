use clap::{Arg, App};
use std::fs::metadata;
use std::fs::File;
mod pidl_parser;
use glob::glob_with;
use glob::MatchOptions;
use std::path::Path;

fn parse(filename: &str){
    println!("Parsing file {}", filename);
    let input_file = File::open(filename).expect("File {} Does not exist");
    let pidl_device: pidl_parser::PIDLDeviceWrapper = serde_yaml::from_reader(input_file).expect("Failed to parse");
    println!("{:?}", pidl_device);
}

fn main() {
    let matches = App::new("PIDL")
        .version("1.0")
        .author("mike7c2")
        .about("Parses PIDL files")
        .arg(Arg::new("input")
            .about("Sets the input file or directory to use")
            .required(true)
            .index(1))
        .arg(Arg::new("v")
            .short('v')
            .multiple_occurrences(true)
            .takes_value(true)
            .about("Sets the level of verbosity"))
        .get_matches();

    let input_name = matches.value_of("input").unwrap();
    let md = metadata(input_name).unwrap();
    
    if (md.is_file()){                      /* If user passes a file parse that file */
        parse(input_name);
    } else if ( md.is_dir() ) {             /* If user passes a folder, parse all the pidl files in the folder */
        let options = MatchOptions {
            case_sensitive: false,
            require_literal_separator: false,
            require_literal_leading_dot: false,
        };
        let glob_str : String = Path::new(input_name).join("*.pidl").to_str().unwrap().to_string();
        for entry in glob_with(&glob_str, options).unwrap() {
            if let Ok(path) = entry {
                let fname = path.to_str().unwrap();
                parse(fname);
            }
        }
    }
}
