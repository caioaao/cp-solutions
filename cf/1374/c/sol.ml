module A = Array
module C = Char
module I = Int64
module L = List
module Q = Queue
module S = String

let pf = Printf.printf
let sf = Scanf.scanf
let ssf = Scanf.sscanf

let read_int () = sf "%d " (fun x -> x)
let read_float () = sf "%f " (fun x -> x)
let read_char () = sf "%c" (fun x -> x)
let read_array read n = A.init n (fun _ -> read ())
let read_list read n = for i = 1 to n do read () done
let read_line () = sf "%s\n" (fun x -> x)
let err s = raise (Failure s)

let inf = int_of_float 1e18
let eps = 1e-11

let count_dangling n xs =
  let rec loop dangling openb i =
    if i = n then dangling
    else if xs.[i] = '(' then loop dangling (openb + 1) (i + 1)
    else if openb == 0 then loop (dangling + 1) openb (i + 1)
    else loop dangling (openb - 1) (i + 1)
  in loop 0 0 0


let () =
  for i = 1 to (read_int ()) do
    let n = (read_int ()) in
    let s =  (read_line ()) in
    pf "%d\n" (count_dangling n s)
  done
