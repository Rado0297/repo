#lang racket
(require rackunit)
(require rackunit/text-ui)

;clases tasks from github
;ackermann
(define (ackermann m n)
  (cond ((= m 0) (+ n 1))
        ((and (> m 0) (= 0 n)) (ackermann (- m 1) 1))
        ((and (> m 0) (> n 0)) (ackermann (- m 1) (ackermann m (- n 1))))
  )
)

(provide (all-defined-out))


(define (all-equal? xs)
  (cond ((null? xs) #t)
        ((null? (cdr xs)) #t)
        (else (and (= (car xs)
                      (cadr xs))
                   (all-equal? (cdr xs))))))

(define (permute xs)
  (if (= (length xs) 1)
    (list xs)
    (apply
      append
        (map (lambda (element)
           (map (lambda (x) (cons element x))
               (permute (remove element xs))))
        xs)
    )
  )
)

;1.3 - Съчинете процедура, която по дадени три числа, намира сумата от квадратите на по-големите две от тях.
; За по-удобно, може да разбиете задачата на по-малки такива.
(define (square-sum a b)
  (+ (* a a) (* b b))
)

(define (squares-sum-bigger-two a b c)
  (cond ((and (> a c) (> b c)) (square-sum a b))
        ((and (> a b) (> c b)) (square-sum a c))
        ((and (> b a) (> c a)) (square-sum b c))
  )
)

; 1.4 - Съчинете процедура, която намира сумата на числата в даден затворен интервал.
(define (sum-interval start end)
  (if (> start end)
      0
      (+ start (sum-interval (+ 1 start) end)))
)

; 1.5 - Търсим процедура, която намира броя цифри на дадено число
; Трябва да работи и за отрицателни числа.
(define (count-digits number)
  (if (< number 0)
      (count-digits (* number -1))
      (if (< number 10) 1 (+ (count-digits (quotient number 10)) 1))
  )
)

; 1.6 - Съчинете процедура, която обръща цифрите на дадено число.
; Трябва да работи и за отрицателни числа.
(define (reverse-digits number)
  (if (and (> number -10) (< number 10))
      number
      (+ (* (remainder number 10) (expt 10 (count-digits (quotient number 10)))) (reverse-digits (quotient number 10)))
  )
)

; 1.7 - Търсим процедура, която проверява дали едно число е палиндром.
; Трябва да работи и за отрицателни числа.
(define (palindrome? number)
  (if (< number 0)
      (palindrome? (* number -1))
      (if (= number (reverse-digits number)) #t #f)
  )
)

; Искаме да проверим дали число е просто.
(define (prime? number)
  (define (prime-helper number num)
    (cond
      ((or (= number 0) (= number 1)) #f)
      ((= (modulo number num) 0) #f)
      ((<= num (sqrt number)) #t)
      (else (prime-helper number (- num 1)))
      )
    )
   (prime-helper number (- number 1))
)

; Обръщаме число в двоична бройна система
(define (to-binary number)
  (cond ((= number 0) (* number 10))
        (else (if (= (remainder number 2) 0)
                  (* (to-binary (quotient number 2)) 10)
                  (+ (* (to-binary (quotient number 2)) 10) 1)
              )
        )
  )
)

; Обръщаме число от двоична в десетична бройна система
(define (to-decimal number)
  (define (to-decimal-helper number power)
    (if (= number 0)
        number
        (+ (to-decimal-helper (quotient number 10) (+ power 1)) (* (expt 2 power) (modulo number 10)))
    )
  )
  (to-decimal-helper number 0)
)

; Търсим сумата от цифрите на дадено число.
; Процедурата да генерира итеративен процес.
(define (sum-digits number)
  (define (helper number result)
    (if(= number 0)
       result
       (helper (quotient number 10) (+ result (modulo number 10)))
    )
  )
  (helper number 0)
)

; Стъпвайки на дефиницията за бързо повдигане на степен,
; търсим такава, която генерира итеративен процес
(define (expt x n)
  (define (helper x n result)
    (cond
      ((= n 0) result)
      ((= (modulo n 2) 1) (helper (* x x) (quotient n 2) (* result x)))
      (else (helper (* x x) (quotient n 2) result))
      )
    )
  (helper x n 1)
)

; Търсим процедура, която проверява дали дадено число завършва на дадено друго.
(define (ends-with? number test)
  (cond
    ((< test 10) (if (eq? (modulo number 10) (modulo test 10)) #t #f))
    ((not (eq? (modulo number 10) (modulo test 10))) #f)
    (else (ends-with? (quotient number 10) (quotient test 10)))
  )
)

; Функцията sum, която видяхме на упражнение.
; Да стане по итеративен начин.
(define (sum start end term next)
  (define (helper start end term next result)
    (if(> start  end)
       result
       (helper (next start) end term next (+ result (term start)))
       )
    )
  (helper start end term next 0)
)

(define (f1 x)
(define (f1-help a)
(if (= a 0) 0 (- a 1)))
(f1-help (f2 (- x 1))))
(define (f2 x)
(define (f2-help a)
(if (= a 2) 1 (+ a 1)))
(if (= x 0) 0
(f2-help (f1 (- x 1)))))



;from today 22.01.2018
(define (sort_list L)
  ;(if (null? L)
  ;    #t
  ;    (if (> (car L) (cadr L))
  ;        #t
  ;        #f
  ;    )
  ;)
  ;(sort_list (cdr L))
  (void)
)

(define (sum-of-interval a b)
  (if (> a b)
      0
      (+ a (sum-of-interval (+ a 1) b)))
)

(define (prod-of-interval a b)
  (if (= a b)
      a
      (* a (prod-of-interval (+ a 1) b)))
)

(define (accumulate op null-value term a next b)
  (if (> a b)
      null-value
      (op (term a)
          (accumulate op null-value term (next a) next b)))
)

(define (y a m n)
  (void)
)