#lang racket
(require rackunit)
(require rackunit/text-ui)
(require "make-matrix.rkt")
(require "get-row.rkt")
(require "get-col.rkt")

(define (rowByCol xs1 xs2)
  (if (null? xs2)
      0
      (+ (* (car xs1) (car xs2)) (rowByCol (cdr xs1) (cdr xs2)))
  )
)

(define (rowByMatrix row m2 k)
  (if (= (- (length row) 1) k)
      '()
      (cons (rowByCol row (get-column m2 k)) (rowByMatrix row m2 (+ 1 k)))
  )
)

; Търсим произведението на две матрици
(define (matrix* m1 m2)
  (if (null? m1)
      '()
      (cons (rowByMatrix (car m1) m2 0) (matrix* (cdr m1) m2))
  )
)

(define tests
  (test-suite "Multiplication tests"
    (let ((first-matrix (make-matrix (range 1 7) 2 3))
          (second-matrix (make-matrix (range 7 13) 3 2))
          (expected-result (make-matrix '(58 64 139 154) 2 2)))
      (check-equal? (matrix* first-matrix second-matrix) expected-result))
  )
)

(run-tests tests 'verbose)