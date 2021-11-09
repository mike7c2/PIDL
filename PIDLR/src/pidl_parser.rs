use serde::{Serialize, Deserialize};

#[derive(Serialize, Deserialize, Debug)]
pub struct PIDLRegion{
    name : String,
    description : Option<String>,
    offset : usize,
    size : usize
}

#[derive(Serialize, Deserialize, Debug)]
pub struct PIDLEnumeratedValue{
    name : String,
    description : Option<String>,
    value : String
}

#[derive(Serialize, Deserialize, Debug)]
pub struct PIDLField{
    name : String,
    description : Option<String>,
    bitRange : String,
    enumeratedValues : Option<Vec<PIDLEnumeratedValue>>
}

#[derive(Serialize, Deserialize, Debug)]
pub struct PIDLRegister{
    name : String,
    description : Option<String>,
    offset : usize,
    size : usize,
    fields : Option<Vec<PIDLField>>
}

#[derive(Serialize, Deserialize, Debug)]
pub struct PIDLDatasheet{
    link : String,
    title : String,
    revision : String
}

#[derive(Serialize, Deserialize, Debug)]
pub struct PIDLDevice{
    name : String,
    description : Option<String>,
    datasheet : PIDLDatasheet,
    addressWidth : usize,
    registerSize : usize,
    registers : Vec<PIDLRegister>,
    regions : Option<Vec<PIDLRegion>>
}

#[derive(Serialize, Deserialize, Debug)]
pub struct PIDLDeviceWrapper{
    device: PIDLDevice
}