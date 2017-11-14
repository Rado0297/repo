#lang racket
(require rackunit)
(require rackunit/text-ui)

; Търсим функция, която връща списък от всички без първите n елемента на даден такъв.

(define (helper n xs start)
  (if (= n start) (cdr xs)
      (helper n (cdr xs) (+ 1 start)))
)

(define (drop n xs)
  (helper n xs 0)
)

(define tests
  (test-suite "Take tests"
     (check-equal? (drop 2 '(1 2 3 4)) '(3 4))
     (check-equal? (drop 0 '(2 9 2)) '(2 9 2))
     (check-equal? (drop 2134 '(9 7 2 3)) '())
  )
)

(run-tests tests 'verbose)