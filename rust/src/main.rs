use std::time::Duration;
use std::time::Instant;

fn some_kind_of_uppercase_first_letter(s: &str) -> String {
    let mut c = s.chars();
    match c.next() {
        None => String::new(),
        Some(f) => f.to_uppercase().collect::<String>() + c.as_str(),
    }
}

fn do_fizzbuzz(turns: i32, type_fb: &str) -> bool{
    let mut first_w = String::from("");
    if type_fb == "bizz"{
        // let first_w = String::from("Bizz");
        first_w = String::from("Bizz");
    }
    else{
        first_w = String::from("Fizz");
    }

    let first_w: &str = &first_w;
    for i in 1..turns+1 {
        let mut kwd: String = String::from("");

        if i % 3 == 0{
            kwd += first_w;
        } if i % 5 ==0{
            kwd += "Buzz"
        } if &kwd == ""{
            kwd = i.to_string();
        }
        println!("{}", kwd);
    }
    true
}

fn play_fizzbuzz(turns: i32, type_fb: &str) -> bool{
    let mut first_w = String::from("");
    if type_fb == "bizz"{
        // let first_w = String::from("Bizz");
        first_w = String::from("Bizz");
    }
    else{
        first_w = String::from("Fizz");
    }

    let first_w: &str = &first_w;
    let start = Instant::now();
    std::thread::sleep(Duration::from_millis(200));

    for i in 1..turns+1{
        // println!("{}", i.to_string());
        let mut kwd: String = String::from("");
        let mut ans = String::from("");
        let mut ans_c = String::from("");
        if i % 2 == 0{
            ans = return_input();
            ans_c = some_kind_of_uppercase_first_letter(&ans)
        }

        if i % 3 == 0{
            kwd += first_w;
        } if i % 5 ==0{
            kwd += "Buzz"
        } if &kwd == ""{
            kwd = i.to_string();
        }
        
        if i % 2 != 0{
            let word: &str = &kwd;
            println!("{}", word);
        }
        if i % 2 == 0 && (&ans != &kwd && &ans_c != &kwd){
            println!("You missed!");
            return false
        }
    }
    let end = Instant::now();
    println!("You win!");
    println!("Clear time[s]: {:?}, turns: {}", end-start, turns.to_string());

    true
}

fn return_input() -> String{
    let mut line = String::new();
    // let b1: i32 = std::io::stdin().read_line(&mut line).unwrap() as i32;
    std::io::stdin().read_line(&mut line).ok();
    let line = line.trim().to_string();
    line
}

fn main() {

    // do_fizzbuzz(16,"fizz");

    let mut line = String::new();
    println!("Press Enter to stasrt!");
    let b1: i32 = std::io::stdin().read_line(&mut line).unwrap() as i32;

    if b1 > 0{
        play_fizzbuzz(16, "fizz");
    }
}