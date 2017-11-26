#lang racket
(require rackunit)
(require rackunit/text-ui)
(require (only-in "./make-matrix.rkt" make-matrix))
(require (only-in "./get-col.rkt" get-column get-elem))

; Искаме да можем да взимаме елемента на ред i и колона j в дадена матрица

(define (get-element matrix i j)
  (get-elem (get-column matrix j) i)
)

(define tests
  (test-suite "Get element tests"
      (check-equal? (get-element (make-matrix (range 1 7) 2 3) 1 2) 6)
      (check-equal? (get-element (make-matrix (range 1 101) 4 5) 2 2) 13)
  )
)

(run-tests tests 'verbose)