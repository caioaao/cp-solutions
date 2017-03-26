(defun swaps (s last res)
  (if s
      (swaps (cdr s) (car s)
             (+ res (if (equal (car s) last) 0 1)))
      (+ res (if (equal #\- last) 1 0))))

(defun solve ()
  (let ((s (coerce (read-line) 'list)))
    (swaps s (car s) 0)))

(defun main ()
  (loop for case-num from 1 to (read) do
       (format t "Case #~a: ~a~%" case-num (solve))))
