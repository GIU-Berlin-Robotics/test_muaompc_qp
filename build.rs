extern crate bindgen;

use std::{env, fs};
use std::path::PathBuf;

use std::process::Command;
//use std::path::Path;
/*
Check that when you compile MUAOMPC, you use these flags:
"arm-none-eabi-gcc" "-O0" "-ffunction-sections" "-fdata-sections" "-g" "-fno-omit-frame-pointer" "-mthumb" "-march=armv7-m" "-Wall" "-Wextra" "-o" "...out/ccode/myinc.o" "-c" "ccode/myinc.c"
*/
fn read_c_files() -> Vec<String> {
    let mut src_dir = env::current_dir().expect("BAD");
    src_dir.push("muaompc_arduino/");
//    let sds = src_dir.as_os_str().clone();
    let empty = String::from("");
    let paths = fs::read_dir(&src_dir).expect("msg");
    let mut names = paths.map(|entry| {
        let entry = entry.unwrap();
      
        let entry_path = entry.path();
      
        let file_name = entry_path.file_name().unwrap();
      
        let file_name_as_str = file_name.to_str().unwrap();
      
        let file_name_as_string = String::from(file_name_as_str);

        let name = if file_name_as_string.ends_with(".c") {
            let mut sss = String::from(src_dir.to_string_lossy().clone());
            sss.push_str(file_name_as_string.as_str());
            sss
        } else {
            empty.clone()
        };
        name
      }).collect::<Vec<String>>();

      names.retain(|x| !empty.eq(x));  // retain non empty
      println!("{:?}", names);
      names
}

fn main() {
    cc::Build::new()
    .files(read_c_files())
    .compile("libmuaompc.a");
    /*
    cc::Build::new()
        .files()
        .
        cc::Build::new()
        .file("ccode/myinc.c")
        .compile("myinc");
    */
    // Tell cargo to tell rustc to link the system bzip2
    // shared library.

    println!("cargo:rustc-link-search=muaompc_arduino");
    println!("cargo:rustc-link-lib=static=muaompc");

    // Tell cargo to invalidate the built crate whenever the wrapper changes
    println!("cargo:rerun-if-changed=wrapper.h");


    // The bindgen::Builder is the main entry point
    // to bindgen, and lets you build up options for
    // the resulting bindings.
    let bindings = bindgen::Builder::default()
        // The input header we would like to generate
        // bindings for.
        .header("wrapper.h")
        // Tell cargo to invalidate the built crate whenever any of the
        // included header files changed.
        .parse_callbacks(Box::new(bindgen::CargoCallbacks))
        .ctypes_prefix("cty")
        .use_core()
        // Finish the builder and generate the bindings.
        .generate()
        // Unwrap the Result and panic on failure.
        .expect("Unable to generate bindings");

    // Write the bindings to the $OUT_DIR/bindings.rs file.
    let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());
    bindings
        .write_to_file(out_path.join("bindings.rs"))
        .expect("Couldn't write bindings!");
}
