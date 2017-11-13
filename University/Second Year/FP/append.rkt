#lang racket
(require rackunit)
(require rackunit/text-ui)

; Търсим функция, която конкатенира два списъка


(define (append xs ys)
  (cond ((null? xs) ys)
        ((null? ys) xs)
        (else (cons xs ys))
  )
)

(define (denestify lst)
  (cond ((null? lst) '())
        ((pair? (car lst))
         (append (denestify (car lst))
                 (denestify (cdr lst))))
        (else (cons (car lst) (denestify (cdr lst))))))

(define tests
  (test-suite "append tests"
    (check-equal? (append '(5 9 2) '(1)) '(5 9 2 1))
    (check-equal? (append '() '(2 3)) '(2 3))
    (check-equal? (append '(2 3) '()) '(2 3))
    (check-equal? (append '(1 8 6 2 3) '(2 3)) '(1 8 6 2 3 2 3))
  )
)

(run-tests tests 'verbose)