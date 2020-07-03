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
let read_int64 () = sf "%d " (fun x -> I.of_int x)
let read_float () = sf "%f " (fun x -> x)
let read_array read n = A.init n (fun _ -> read ())
let read_list read n = l_init n (fun _ -> read ())
let err s = raise (Failure s)

let inf = int_of_float 1e18
let eps = 1e-11

let delta0 k x = I.sub k  (I.rem x k)

let deltas k d0s =
  let rec loop acc prevMod prevVal = function
    | [] -> L.rev acc
    | hd::tl when hd = prevMod -> let newVal = I.add prevVal k in
                                  loop (newVal::acc) prevMod newVal tl
    | hd::tl -> loop (hd::acc) hd hd tl
  in loop [] 0L 0L d0s

let countSteps k deltas =
  let rec loop acc x = function
    | [] -> acc
    | hd::tl -> loop (I.succ (I.add acc (I.sub hd x))) (I.succ hd) tl
  in loop 0L 0L deltas

let solveFor k xs =
  L.map (delta0 k) xs
  |> L.filter (fun x -> I.compare x k != 0)
  |> L.sort I.compare
  |> deltas k
  |> L.sort I.compare
  |> countSteps k

let () =
  for _ = 1 to (read_int ()) do
    let n = read_int () in
    let k = read_int64 () in
    pf "%Ld\n" (solveFor k (read_list read_int64 n))
  done
