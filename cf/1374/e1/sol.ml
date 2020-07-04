module A = Array
module C = Char
module I = Int64
module L = List
module Q = Queue
module S = String

let pf = Printf.printf
let sf = Scanf.scanf
let ssf = Scanf.sscanf

let l_init n f =
  let rec loop acc i =
    if i >= n then acc else loop ((f i) :: acc) (i+1)
  in List.rev (loop [] 0)

let read_int () = sf "%d " (fun x -> x)
let read_int64 () = sf "%Ld " (fun x -> x)
let read_float () = sf "%f " (fun x -> x)
let read_list read n = l_init n (fun _ -> read ())
let read_array read n = A.init n (fun _ -> read ())
let err s = raise (Failure s)

let l_take_opt n l =
  let rec loop acc i = function
    | _ when i = n -> Some (L.rev acc)
    | hd::tl -> loop (hd::acc) (succ i) tl
    | [] -> None
  in loop [] 0 l

let inf = int_of_float 1e18
let eps = 1e-11

let map2_min f l1 l2 =
  let rec loop acc = function
  | (_, []) | ([], _) -> acc
  | (a1::l1, a2::l2) -> loop ((f a1 a2)::acc) (l1, l2)
  in loop [] (l1, l2)

let read_book () =
  let t = read_int64() in
  let a = read_int() in
  let b = read_int() in
  (t, a, b)

let partition books =
  let rec loop common_ts alice_ts bob_ts = function
    | [] -> common_ts, alice_ts, bob_ts
    | (t, a, b)::tl when a = 1 && b = 1 -> loop (t::common_ts) alice_ts bob_ts tl
    | (t, a, b)::tl when a = 1 -> loop common_ts (t::alice_ts) bob_ts tl
    | (t, a, b)::tl when b = 1 -> loop common_ts alice_ts (t::bob_ts) tl
    | _ -> assert false
  in loop [] [] [] books

let ranked_times (ts, a_ts, b_ts) =
  map2_min I.add (L.sort I.compare a_ts) (L.sort I.compare b_ts)
  |> L.append ts
  |> L.sort I.compare

let solve k ts =
  match l_take_opt k ts with
  | None -> -1L
  | Some selection -> L.fold_left I.add 0L selection

let () =
  let rec loop () =
    try let n = read_int() in
        let k = read_int() in
        (read_list read_book n)
        |> L.filter (fun (_, a, b) -> (a != 0) || (b != 0))
        |> partition
        |> ranked_times
        |> solve k
        |> pf "%Ld\n";
        loop ()
    with End_of_file -> ()
  in loop ()
