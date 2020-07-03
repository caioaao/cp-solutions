let divBy3 x =
  let rec loop acc x' =
    if x' <= 1 then Some acc
    else if (x' mod 3) = 0 then loop (acc + 1) (x' / 3)
    else None
  in loop 0 x

let divBy6 x =
  let rec loop acc x' =
    if (x' mod 6) = 0 then loop (acc + 1) (x' / 6) else acc
  in loop 0 x

let rec without6 x =
  if (x mod 6) = 0 then without6 (x / 6) else x

let solveFor x =
  match divBy3 (without6 x) with
  | None -> -1
  | Some x' -> (divBy6 x) + (x' * 2)

let read_int () = Scanf.scanf "%d " (fun x -> x)

let () =
  for i = 1 to (read_int ()) do
    read_int ()
    |> solveFor
    |> Printf.printf "%d\n"
  done
