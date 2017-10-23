#####
# Copyright (c) 2017 Armando Faz <armfazh@ic.unicamp.br>.
# Institute of Computing.
# University of Campinas, Brazil.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as
# published by the Free Software Foundation, version 3.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.
#####
#Sagemath script

R.<x1,y1,x2,y2,A,B> = PolynomialRing(Rationals(),6,'x1,y1,x2,y2,A,B')
I = R.ideal([  
    B*y1**2-x1**3-A*x1**2-x1,
    B*y2**2-x2**3-A*x2**2-x2  ])
Qu = R.quotient(I)
FQu = Frac(Qu)
evaluate = lambda F,_x_: FQu(F.subs(x=_x_).rational_simplify())

def addMontgomery(X1,Y1,X2,Y2):
    global A, B
    Xs = B*((Y1-Y2)/(X1-X2))**2-A-X1-X2
    Ys = (2*X1+X2+A)*(Y2-Y1)/(X2-X1)-B*(Y2-Y1)**3/(X2-X1)**3-Y1
    return Xs,Ys

xs,ys = addMontgomery(x1,y1,x2,y2)
xd,yd = addMontgomery(x1,y1,x2,-y2)

alpha = (x1-x2)**2
betta = 2*(x1*x2+1)*(x1+x2)+4*A*x1*x2
gamma = (x1*x2-1)**2
delta = -4*B*y1*y2

rel_add = FQu(xs+xd)
rel_dif = FQu(xs-xd)
rel_pro = FQu(xs*xd)

#Vefiying Relations
assert(rel_add == betta/alpha )
assert(rel_pro == gamma/alpha )
assert(rel_dif == delta/alpha )

# Renes&Smith's polynomial
f = alpha*x**2-betta*x+gamma

# Testing zero values of f
assert( evaluate(f,xs) == 0 )
assert( evaluate(f,xd) == 0 )

# Defining g0 and g1
g0 = alpha*x**2-delta*x-gamma
g1 = alpha*x**2+delta*x-gamma

# Testing zero values of g0 and g1
assert( evaluate(g0, xs) == 0 )
assert( evaluate(g0,-xd) == 0 )
assert( evaluate(g1,-xs) == 0 )
assert( evaluate(g1, xd) == 0 )

# Defining h0 and h1
h0 = 2*alpha*x-delta-betta
h1 = (delta-betta)*x+2*gamma

# Testing zeros of h0 and h1
assert( evaluate(h0, xs) == 0 )
assert( evaluate(h1, xs) == 0 )
