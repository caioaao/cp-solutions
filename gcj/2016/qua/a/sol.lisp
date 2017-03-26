(defun which (x)
  (if (zerop x)
      0
      (logior (which (floor x 10)) (ash 1 (mod x 10)))))

(defconstant complete-bm (which 1234567890))

(defun solve% (x n bm)
  (let ((bm (logior bm (which x))))
    (if (eql bm complete-bm)
        x
        (solve% (+ n x) n bm))))

(defun solve ()
  (let ((n (read)))
    (if (zerop n)
        "INSOMNIA"
        (solve% n n 0))))

(defun main ()
  (loop for case-num from 1 to (read) do
       (format t "Case #~a: ~a~%" case-num (solve))))
