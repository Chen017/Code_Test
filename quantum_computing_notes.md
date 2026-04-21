---
title: quantum_computing (11)
date: 2026-04-21T19:40:49+08:00
lastmod: 2026-04-21T19:41:13+08:00
---

# quantum_computing (11)

Introduction to Quantum Computing

Adam Sawicki

2026

## Introduction: Quantum vs. Classical Theory

The fundamental distinction between the classical and quantum paradigms lies in predictability: quantum theory is inherently probabilistic, meaning we can only determine the likelihood of a specific outcome. While classical mechanics accurately describes macroscopic (”large”) systems, it fails to explain phenomena at the microscopic (”small”) scale. Conversely, quantum mechanics provides a universally valid description across all scales; however, the immense complexity of applying it to macroscopic systems makes it highly impractical.

## 1 The Postulates of Quantum Mechanics

Postulate (System States). Any quantum system is described by a Hilbert space $(\mathcal{H},\langle\cdot|\cdot\rangle)$. A pure state of a system is given by $|\Psi\rangle$, with $\|\psi\|=1$. For our purposes, we assume $\dim\mathcal{H}=n<\infty$.

Postulate (Observables). Any physically measurable quantity of a system is represented by a self-adjoint (Hermitian) operator $F:\mathcal{H}\rightarrow\mathcal{H}$. We call such an operator an observable. The possible measurement values of $F$ are given by the spectrum of $F$, denoted $\sigma(F)$.

Postulate (Measurement Probability). The probability that for a system in the pure state $|\Psi\rangle$, a measurement of the observable described by $F$ yields $\lambda\in\sigma(F)$ is given by:

$\mathbb{P}_{\Psi}(\lambda)=\left\|P_{\lambda}\left|\Psi\right\rangle\right\|^{2}=\left\langle P_{\lambda}\Psi\right|P_{\lambda}\Psi\rangle=\left\langle\Psi\right|P_{\lambda}\Psi\rangle$

where $P_{\lambda}$ is the orthogonal projection onto the eigenspace $V_{\lambda}$ corresponding to $|\Psi\rangle$. Clearly, $\mathbb{P}_{\Psi}(\lambda)\geq 0$.

Remark (Verification of Probability Measure). We need to verify that $\mathbb{P}_{\Psi}(\lambda)$ is indeed a good probability measure. Given the spectrum $\sigma(F)=\{\lambda_{1},\ldots,\lambda_{r}\}$ and choosing an orthonormal basis of $V_{\lambda_{i}}$ to be $\{e_{i,k}\}_{k=1}^{d_{i}}$ we can write

$P_{\lambda_{i}}=\sum_{k=1}^{d_{i}}\left|e_{i,k}\right\rangle\left\langle e_{i,k}\right|,\ \ \mathcal{H}=\bigoplus_{i=1}^{r}V_{\lambda_{i}},$

where

---

and therefore

$$
\begin{array}{l}
\sum_{\lambda \in \sigma (F)} \mathbb{P}_{\Psi} (\lambda) = \sum_{i = 1}^{r} \langle \Psi | P_{\lambda_{i}} \Psi \rangle \\
= \sum_{i = 1}^{r} \sum_{k = 1}^{d_{i}} \left\langle \Psi \right| e_{i, k} \left\langle e_{i, k} \right| \Psi \rangle \\
= \sum_{i = 1}^{r} \sum_{k = 1}^{d_{i}} \left| \left\langle \Psi \right| e_{i, k} \right\rangle^{2} \\
= \| \Psi \|^{2} = 1 \quad (\text{since } \{e_{i, k}\} \text{ is an ONB of } \mathcal{H})
\end{array}
$$

**Fact (Expected Value).**  If a system is in the state $|\Psi\rangle$, then the expected value of $F$ is given by $\langle F\rangle_{\Psi} = \langle \Psi | F\Psi \rangle$.

**Proof.**  Using the spectral decomposition $F = \lambda_1 P_{\lambda_1} + \cdots + \lambda_r P_{\lambda_r}$:

$$
\begin{array}{l}
\langle F \rangle_{\Psi} = \langle \Psi | \lambda_1 P_{\lambda_1} + \cdots + \lambda_r P_{\lambda_r} | \Psi \rangle \\
= \sum_{k = 1}^{n} \lambda_{k} \left\langle \Psi \right| P_{\lambda_{k}} \Psi \rangle \\
= \sum_{k = 1}^{n} \lambda_{k} \mathbb{P}_{\Psi} (\lambda_{k})
\end{array}
$$

☐

**Postulate (State Collapse).**  Assume a quantum system is in the state $|\Psi\rangle$. If the measurement of an observable $F$ yields $\lambda \in \sigma(F)$, then after the measurement, the system is in the state:

$$
| \varphi \rangle = \frac{P_{\lambda} | \Psi \rangle}{\| P_{\lambda} | \Psi \rangle \|}.
$$

**Example.**  Let $|\Psi\rangle$ be an eigenvector of $F$ with an eigenvalue $\mu$. Then $\mathbb{P}_{\Psi}(\mu) = 1$, $\mathbb{P}_{\Psi}(\lambda) = 0$ for $\lambda \in \sigma(F), \lambda \neq \mu$, and $\langle F\rangle_{\Psi} = \mu$.

**Proof.**  By direct substitution:

$$
\mathbb{P}_{\hat{\Psi}} (\lambda) = \left\langle \hat{\Psi} \right| P_{\lambda} \hat{\Psi} \rangle = \left\langle e^{i f} \Psi \right| P_{\lambda} e^{i f} \Psi \rangle = \langle \Psi | P_{\lambda} \Psi \rangle = \mathbb{P}_{\Psi} (\lambda)
$$

☐

## Summary: Measurement as a Probability Space

Let $\mathcal{H} = \mathbb{C}^d$ be a Hilbert space describing a Quantum System (Q.S.). Assume the system is in a pure state given by a normalized vector $|\Psi\rangle$ (where $\| \Psi \| = 1$),

---

and let $F:\mathcal{H}\to\mathcal{H}$ be an observable (a Hermitian operator, $F^{\dagger}=F$). Using the spectral decomposition, we can write the observable as:

$F=\sum_{i=1}^{r}\lambda_{i}P_{\lambda_{i}},$

where $r$ is the number of diffrent eigenvalues. When we perform a measurement of $F$ on the state $|\Psi\rangle$, it formally defines a probability space given by the triplet:

$(\sigma(F),2^{\sigma(F)},\mathbb{P}_{\Psi})$

This probability space is uniquely determined by the chosen state and the observable, where:

- Sample Space ($\sigma(F)$): The spectrum of $F$, representing all possible measurement outcomes (the eigenvalues $\lambda_{i}$).
- Event Space ($2^{\sigma(F)}$): The power set of the spectrum, representing all possible combinations of outcomes.
- Probability Measure ($\mathbb{P}_{\Psi}$): The probability of measuring a specific eigenvalue $\lambda_{i}$, given by:

$\mathbb{P}_{\Psi}(\lambda_{i})=\langle\Psi|\,P_{\lambda_{i}}\,|\Psi\rangle$

Wavefunction Collapse: Immediately following the measurement that yields an outcome $\lambda$, the quantum state transitions (collapses) to a new normalized state:

$|\Psi\rangle\longmapsto\frac{P_{\lambda}\,|\Psi\rangle}{\|P_{\lambda}\,|\Psi\rangle\|}$

Fact (Global Phase Independence). Let $|\Psi\rangle\in\mathcal{H}$ and let $\left|\hat{\Psi}\right\rangle=e^{if}\,|\Psi\rangle$. Then for any $F$, $\mathbb{P}_{\hat{\Psi}}(\lambda)=\mathbb{P}_{\Psi}(\lambda)$

Remark (Pure States as Rays). Conclusion: Pure states are equivalence classes of vectors in $\mathcal{H}$, where for $v,w\in\mathcal{H}$ we say that $v\sim w$ iff $v=\lambda w$ for $\lambda\in\mathbb{C},\lambda\neq 0$. Pure states are points in the projective space $P(\mathcal{H})$.

### 1.1 Uncertainty and Compatible Observables

Definition (Uncertainty). The uncertainty of an observable $F$ in the state $|\Psi\rangle$ is defined by:

$\Delta_{\Psi}(F)=\sqrt{\langle\Psi|\,[F-\langle F\rangle_{\Psi}I]^{2}\Psi\rangle}=\sqrt{\langle(F-\langle F\rangle_{\Psi}I)^{2}\rangle_{\Psi}}$

Fact. The uncertainty of an observable $F$ in the state $|\Psi\rangle$ is the standard deviation

---

Expansion of Variance. Note that $\langle F\rangle_{\Psi}\in\mathbb{R}$ and $(F-\langle F\rangle_{\Psi}I)^{\dagger}=F-\langle F\rangle_{\Psi}I$. Evaluating the squared term inside the expectation:

$\langle\Psi|\,(F-\langle F\rangle_{\Psi}I)^{2}\,|\Psi\rangle$ $=\langle(F-\langle F\rangle_{\Psi}I)\Psi|\,(F-\langle F\rangle_{\Psi}I)\Psi\rangle$  
$=\langle\Psi|\,F^{2}\Psi\rangle-2\langle F\rangle_{\Psi}\,\langle\Psi|\,F\Psi\rangle+\langle F\rangle_{\Psi}^{2}$  
$=\langle F^{2}\rangle_{\Psi}-\langle F\rangle_{\Psi}^{2}=\sum_{i=1}^{n}\lambda_{i}^{2}\,\langle\Psi|\,P_{\lambda_{i}}\,|\Psi\rangle-\left(\sum_{i=1}^{n}\lambda_{i}\mathbb{P}_{\Psi}(\lambda_{i})\right)^{2}$  
$=\sum_{i=1}^{n}\lambda_{i}^{2}\mathbb{P}_{\Psi}(\lambda_{i})-\left(\sum_{i=1}^{n}\lambda_{i}\mathbb{P}_{\Psi}(\lambda_{i})\right)^{2}$

which defines the variance, making $\Delta_{\Psi}(F)$ the standard deviation. ∎

###### Fact.

$\Delta_{\Psi}(F)=0$ iff $F\,|\Psi\rangle=\lambda\,|\Psi\rangle$ for some $\lambda\in\sigma(F)$.

###### Proof.

We must prove both directions. $(\implies)$ Assume $\Delta_{\Psi}(F)=0$. By definition, the variance can be written as the squared norm: $\Delta_{\Psi}^{2}(F)=\|(F-\langle F\rangle_{\Psi}I)\,|\Psi\rangle\|^{2}$. Hence $\Delta_{\Psi}^{2}(F)=0\implies\|(F-\langle F\rangle_{\Psi}I)\,|\Psi\rangle\|^{2}=0$. By the properties of the norm, the vector itself must be the zero vector:

$(F-\langle F\rangle_{\Psi}I)\,|\Psi\rangle=0\implies F\,|\Psi\rangle=\langle F\rangle_{\Psi}\,|\Psi\rangle$

Meaning $|\Psi\rangle$ is an eigenvector of $F$ with an eigenvalue $\lambda=\langle F\rangle_{\Psi}\in\sigma(F)$. $(\iff)$ Assume $|\Psi\rangle$ is an eigenvector of $F$ such that $F\,|\Psi\rangle=\lambda\,|\Psi\rangle$ for some $\lambda\in\sigma(F)$. First, the expectation value is:

$\langle F\rangle_{\Psi}=\langle\Psi|\,F\,|\Psi\rangle=\lambda\,\langle\Psi|\Psi\rangle=\lambda$

(assuming $|\Psi\rangle$ is normalized). Now, calculating the uncertainty:

$\Delta_{\Psi}^{2}(F)=\|(F-\langle F\rangle_{\Psi}I)\,|\Psi\rangle\|^{2}=\|(F-\lambda I)\,|\Psi\rangle\|^{2}=\|F\,|\Psi\rangle-\lambda\,|\Psi\rangle\|^{2}=\|0\|^{2}=0$

Thus, $\Delta_{\Psi}(F)=0$. ∎

###### Definition (Compatibility).

Two observables $F,G:\mathcal{H}\to\mathcal{H}$ for some quantum system, $\mathcal{H}$, are called compatible if $[F,G]:=FG-GF=0$. Recall that if $[F,G]=0$ we can find an ONB $S$ in which both $F$ and $G$ are diagonal. If $|\Psi\rangle\in S$ then $\Delta_{\Psi}(F)=0=\Delta_{\Psi}(G)$.

###### Theorem (Robertson-Schrödinger Uncertainty Relation).

Let $F,G:\mathcal{H}\to\mathcal{H}$ be two observables (Hermitian operators) of a quantum system in state $|\Psi\rangle$. Then the product of their variances is bounded by both their commutator and anticommutator:

$\Delta_{\Psi}^{2}(F)\Delta_{\Psi}^{2}(G)\geq\frac{1}{4}\langle\{\hat{F},\hat{G}\}\rangle_{\Psi}^{2}+\frac{1}{4}|\langle[F,G]\rangle_{\Psi}|^{2}$

where $\hat{F}=F-\langle F\rangle_{\Psi}I$, $\hat{G}=G-\langle G\rangle_{\Psi}I$, and $\{A,B\}=AB+BA$ denotes the anticommutator.

---

Proof.

Let us define the deviation operators:

$\tilde{F}=F-\langle F\rangle_{\Psi}I\quad\text{and}\quad\tilde{G}=G-\langle G\rangle_{\Psi}I$

Since $F$ and $G$ are Hermitian, $\tilde{F}$ and $\tilde{G}$ are also Hermitian. The variances are given by the squared norms of the states generated by these operators acting on $|\Psi\rangle$:

$\Delta_{\Psi}^{2}(F)$ $=\langle\Psi|\,\tilde{F}^{2}\,|\Psi\rangle=\left\|\tilde{F}\,|\Psi\rangle\right\|^{2}$  
$\Delta_{\Psi}^{2}(G)$ $=\langle\Psi|\,\tilde{G}^{2}\,|\Psi\rangle=\left\|\tilde{G}\,|\Psi\rangle\right\|^{2}$

Using the Cauchy-Schwarz inequality for vectors $|f\rangle=\tilde{F}\,|\Psi\rangle$ and $|g\rangle=\tilde{G}\,|\Psi\rangle$:

$\Delta_{\Psi}^{2}(F)\Delta_{\Psi}^{2}(G)=\left\|f\right\|^{2}\left\|g\right\|^{2}\geq|\langle f|g\rangle|^{2}=|\,\langle\Psi|\,\tilde{F}\tilde{G}\,|\Psi\rangle\,|^{2}=|\langle\tilde{F}\tilde{G}\rangle_{\Psi}|^{2}$

Now, we decompose the operator product $\tilde{F}\tilde{G}$ into its Hermitian and anti-Hermitian parts. For any two operators, we can write:

$\tilde{F}\tilde{G}=\frac{1}{2}(\tilde{F}\tilde{G}+\tilde{G}\tilde{F})+\frac{1}{2}(\tilde{F}\tilde{G}-\tilde{G}\tilde{F})=\frac{1}{2}\{\tilde{F},\tilde{G}\}+\frac{1}{2}[\tilde{F},\tilde{G}]$

Because $\tilde{F}$ and $\tilde{G}$ are Hermitian, their anticommutator $\{\tilde{F},\tilde{G}\}$ is a Hermitian operator, meaning its expectation value is purely real. Conversely, their commutator $[\tilde{F},\tilde{G}]$ is an anti-Hermitian operator, meaning its expectation value is purely imaginary. Taking the expectation value of $\tilde{F}\tilde{G}$:

$\langle\tilde{F}\tilde{G}\rangle_{\Psi}=\frac{1}{2}\langle\{\tilde{F},\tilde{G}\}\rangle_{\Psi}+\frac{1}{2}\langle[\tilde{F},\tilde{G}]\rangle_{\Psi}$

This expresses a complex number $z=x+iy$ where $x=\frac{1}{2}\langle\{\tilde{F},\tilde{G}\}\rangle_{\Psi}\in\mathbb{R}$ and $iy=\frac{1}{2}\langle[\tilde{F},\tilde{G}]\rangle_{\Psi}\in i\mathbb{R}$. The absolute square of this complex number is simply the sum of the squares of its real and imaginary parts:

$|\langle\tilde{F}\tilde{G}\rangle_{\Psi}|^{2}=\frac{1}{4}\langle\{\tilde{F},\tilde{G}\}\rangle_{\Psi}^{2}+\frac{1}{4}|\langle[\tilde{F},\tilde{G}]\rangle_{\Psi}|^{2}$

Finally, note that the commutator of the deviation operators is identical to the commutator of the original operators because the scalar parts (the identity matrices) commute with everything:

$[\tilde{F},\tilde{G}]=[F-\langle F\rangle_{\Psi}I,G-\langle G\rangle_{\Psi}I]=[F,G]$

Substituting this back into our Cauchy-Schwarz result yields the final theorem:

$\Delta_{\Psi}^{2}(F)\Delta_{\Psi}^{2}(G)\geq\frac{1}{4}\langle\{\tilde{F},\tilde{G}\}\rangle_{\Psi}^{2}+\frac{1}{4}|\langle[F,G]\rangle_{\Psi}|^{2}$

∎

## 

---

Remark (Quantum vs. Classical Covariance). In classical probability theory, the covariance between two real-valued random variables $X$ and $Y$ is defined as:

$\mbox{\it Cov}(X,Y)=\mathbb{E}[(X-\mathbb{E}[X])(Y-\mathbb{E}[Y])]$

The classical Cauchy-Schwarz inequality for random variables states that the product of their variances is bounded below by their squared covariance:

$\mbox{\it Var}(X)\,\mbox{\it Var}(Y)\geq\,\mbox{\it Cov}(X,Y)^{2}$

In quantum mechanics, operators generally do not commute, so the order of multiplication matters. The quantum analog of classical covariance must be symmetrized to ensure the result is an observable (i.e., real-valued). This is perfectly captured by the expectation value of the anticommutator divided by two:

$\mbox{\it Cov}_{Q}(F,G)=\frac{1}{2}\langle\{\hat{F},\hat{G}\}\rangle_{\Psi}=\frac{1}{2}\langle(F-\langle F\rangle_{\Psi}I)(G-\langle G\rangle_{\Psi}I)+(G-\langle G\rangle_{\Psi}I)(F-\langle F\rangle_{\Psi}I)\rangle_{\Psi}$

Using this definition, the generalized uncertainty relation can be rewritten as:

$\Delta_{\Psi}^{2}(F)\Delta_{\Psi}^{2}(G)\geq\,\mbox{\it Cov}_{Q}(F,G)^{2}+\frac{1}{4}|\langle[F,G]\rangle_{\Psi}|^{2}$

This form beautifully unifies classical and quantum mechanics. The quantum uncertainty is bounded below by two distinct components:

1. A classical-like term ($\mbox{\it Cov}_{Q}(F,G)^{2}$): This measures the statistical correlation between the two observables, exactly mimicking classical covariance. If $F$ and $G$ are highly correlated, their joint uncertainty must be large, even classically.
2. A purely quantum term ($\frac{1}{4}|\langle[F,G]\rangle_{\Psi}|^{2}$): This arises purely from the non-commutativity of the operators. It has no classical analog.

If we set the quantum term to zero (by considering classical variables that commute), we perfectly recover the standard classical inequality $\,\mbox{\it Var}(F)\,\mbox{\it Var}(G)\geq\,\mbox{\it Cov}(F,G)^{2}$.

### 1.2 Time Evolution

Suppose a closed quantum system is prepared in a pure state $|\Psi(t_{0})\rangle\in\mathcal{H}$ at an initial time $t=t_{0}$. In the absence of any measurements, how does this state evolve over time? This deterministic evolution is governed by the following postulate.

Postulate (Time Evolution and the Schrödinger Equation). The free (unmeasured) time evolution of a quantum system is described by a time-evolution operator $U(t,t_{0})$, which maps the initial state to the state at any time $t$:

$|\Psi(t)\rangle=U(t,t_{0})\,|\Psi(t_{0})\rangle$

---

This operator satisfies the Schrödinger equation:

$i\frac{d}{dt}U(t,t_{0})=H(t)U(t,t_{0}),\quad\text{with the initial condition }U(t_{0},t_{0})=I$

where $H(t):\mathcal{H}\rightarrow\mathcal{H}$ is the Hamiltonian of the system. The Hamiltonian is the observable corresponding to the total energy of the system and is therefore a Hermitian operator ($H(t)=H^{\dagger}(t)$). Consequently, by applying this operator equation to the initial state vector $\left|\Psi(t_{0})\right\rangle$, we recover the Schrödinger equation for the state vector itself:

$i\frac{d}{dt}\Big{(}U(t,t_{0})\left|\Psi(t_{0})\right\rangle\Big{)}=H(t)\Big{(}U(t,t_{0})\left|\Psi(t_{0})\right\rangle\Big{)}\implies i\frac{d}{dt}\left|\Psi(t)\right\rangle=H(t)\left|\Psi(t)\right\rangle$

###### Theorem.

The time evolution operator $U(t,t_{0})$ generated by a Hermitian Hamiltonian $H(t)$ is unitary for all $t$.

###### Proof.

By definition, the operator $U(t,t_{0})$ satisfies the Schrödinger equation:

$i\frac{d}{dt}U(t,t_{0})=H(t)U(t,t_{0})\implies\frac{d}{dt}U(t,t_{0})=-iH(t)U(t,t_{0})$

Taking the Hermitian adjoint of this equation, and recalling that the Hamiltonian is self-adjoint ($H^{\dagger}=H$), we obtain:

$-i\frac{d}{dt}U^{\dagger}(t,t_{0})=U^{\dagger}(t,t_{0})H(t)\implies\frac{d}{dt}U^{\dagger}(t,t_{0})=iU^{\dagger}(t,t_{0})H(t)$

To prove unitarity, we must show that $U^{\dagger}(t,t_{0})U(t,t_{0})=I$ for all $t$. We do this by examining the time derivative of this product. Applying the product rule yields:

$\frac{d}{dt}\left[U^{\dagger}(t,t_{0})U(t,t_{0})\right]$ $=\left(\frac{d}{dt}U^{\dagger}(t,t_{0})\right)U(t,t_{0})+U^{\dagger}(t,t_{0})\left(\frac{d}{dt}U(t,t_{0})\right)$  
$=\big{(}iU^{\dagger}(t,t_{0})H(t)\big{)}U(t,t_{0})+U^{\dagger}(t,t_{0})\big{(}-iH(t)U(t,t_{0})\big{)}$  
$=iU^{\dagger}(t,t_{0})H(t)U(t,t_{0})-iU^{\dagger}(t,t_{0})H(t)U(t,t_{0})$  
$=0$

Since the derivative is zero, the operator product $U^{\dagger}(t,t_{0})U(t,t_{0})$ must be a constant, time-independent operator $M$. To determine $M$, we evaluate the product at the initial time $t=t_{0}$, where $U(t_{0},t_{0})=I$:

$M=U^{\dagger}(t_{0},t_{0})U(t_{0},t_{0})=I^{\dagger}I=I$

Therefore, $U^{\dagger}(t,t_{0})U(t,t_{0})=I$ for all time $t$, proving that the time evolution operator is indeed unitary. ∎

###### Example (Time-Independent Hamiltonian).

A common and highly important scenario occurs when the Hamiltonian $H$ does not explicitly depend on time. Setting the initial time to $t_{0}=0$, the Schrödinger equation simplifies to:

$i\frac{d}{dt}\left|\Psi(t)\right\rangle=H\left|\Psi(t)\right\rangle,\quad\text{with the initial state }\left|\Psi(0)\right\rangle=\left|\Psi_{0}\right\rangle$

---

The solution to this differential equation is given by applying the unitary time evolution operator $U(t)=e^{-itH}$:

$\left|\Psi(t)\right\rangle=e^{-itH}\left|\Psi_{0}\right\rangle$

(This can be easily verified by directly differentiating the state with respect to $t$). To evaluate this matrix exponential, we utilize the spectral decomposition of the Hamiltonian, $H=\sum_{i}E_{i}P_{E_{i}}$, where $E_{i}$ are the energy eigenvalues and $P_{E_{i}}$ are the projection operators onto the corresponding eigenspaces. The time evolution operator can then be written as:

$e^{-itH}=\sum_{i}e^{-itE_{i}}P_{E_{i}}$

Thus

$\left|\Psi(t)\right\rangle=\sum_{i}e^{-itE_{i}}P_{E_{i}}\left|\Psi_{0}\right\rangle$

Stationary States: In the specific case where the initial state is already an energy eigenstate (i.e., $\left|\Psi_{0}\right\rangle=P_{E_{k}}\left|\Psi_{0}\right\rangle$ for some energy $E_{k}$), the state simply evolves by acquiring a global phase factor:

$\left|\Psi(t)\right\rangle=e^{-itE_{k}}\left|\Psi_{0}\right\rangle$

Because global phase factors do not affect probabilities or expectation values, systems prepared in an energy eigenstate will have physical properties that remain completely constant over time.

###### Theorem (Stone’s Theorem on One-Parameter Unitary Groups).

Let $U(t)$ be a continuous one-parameter unitary group. That is, $U(t)$ is a family of unitary operators parameterized by time $t\in\mathbb{R}$, satisfying the initial condition $U(0)=I$ and the group homomorphism property $U(t+s)=U(t)U(s)$. Assume that the derivative of $U(t)$ exists at $t=0$. Then, there exists a unique Hermitian operator $H$ such that:

$U(t)=e^{-itH}$

###### Proof.

By our assumption, the derivative exists at $t=0$. Let us define this constant operator as $A\equiv U^{\prime}(0)$:

$A=\lim_{s\rightarrow 0}\frac{U(s)-U(0)}{s}=\lim_{s\rightarrow 0}\frac{U(s)-I}{s}$

We can use this local property at $t=0$ to find the time derivative of $U(t)$ at any arbitrary time $t$. Utilizing the group property $U(t+s)=U(t)U(s)$, we

---

evaluate the limit:

$\frac{d}{dt}U(t)$ $=\lim_{s\rightarrow 0}\frac{U(t+s)-U(t)}{s}$  
$=\lim_{s\rightarrow 0}\frac{U(t)U(s)-U(t)I}{s}$  
$=U(t)\lim_{s\rightarrow 0}\frac{U(s)-I}{s}$  
$=U(t)A$

This demonstrates that if the derivative exists at $t=0$, the group structure guarantees it exists everywhere! We are now left with a first-order linear differential equation:

$\frac{d}{dt}U(t)=U(t)A,\quad\text{with the initial condition }U(0)=I$

The unique solution to this initial value problem is the matrix exponential:

$U(t)=e^{tA}$

Next, we must determine the algebraic properties of the generator $A$. Because $U(t)$ forms a group, we have $U(t)U(-t)=U(t-t)=U(0)=I$. However, because $U(t)$ is also strictly unitary, we inherently know that $U^{\dagger}(t)U(t)=I$. Equating these two properties implies that the inverse of the operator is equal to both its adjoint and its time-reversal:

$U^{\dagger}(t)=U(-t)$

Substituting our exponential solution $U(t)=e^{tA}$ into this equality yields:

$\left(e^{tA}\right)^{\dagger}=e^{-tA}\implies e^{tA^{\dagger}}=e^{-tA}$

To extract the operators from the exponent, we differentiate both sides with respect to $t$ and evaluate at $t=0$:

$\left.\frac{d}{dt}\right|_{t=0}e^{tA^{\dagger}}=\left.\frac{d}{dt}\right|_{t=0}e^{-tA}\implies A^{\dagger}=-A$

This reveals that $A$ is an anti-Hermitian operator. To connect this to quantum mechanics (where observables are Hermitian), we factor out the imaginary unit $i$ by defining a new operator $H$ such that $A=-iH$. $\square$

###### Remark (Relaxing the Differentiability Assumption).

In the full, mathematically rigorous statement of Stone’s Theorem (particularly necessary for infinite-dimensional Hilbert spaces), the explicit assumption that $U(t)$ is differentiable at $t=0$ can actually be removed. Assuming only that $U(t)$ is strongly continuous (i.e., $\lim_{t\rightarrow 0}U(t)\left|\Psi\right\rangle=\left|\Psi\right\rangle$ for all states $\left|\Psi\right\rangle$) is mathematically sufficient to guarantee the existence of a unique, self-adjoint generator $H$. However, proving the theorem using only the continuity assumption is significantly more complex. It requires the machinery of advanced functional analysis (such as constructing a dense domain using integral operators or resolvents) to meticulously prove that a derivative can be well-defined in the first place.

---

2 Mixed States

So far, we have assumed that our quantum system (Q.S.) is prepared in a specific, known pure state $|\Psi\rangle\in\mathcal{H}$. But what if the preparation procedure itself is probabilistic?

Suppose a quantum system is prepared in one of several possible states $|\Psi_{k}\rangle$, and the classical probability that the system is prepared in the specific state $|\Psi_{k}\rangle$ is given by $p_{k}$. Such a probabilistic mixture of pure states is known as a statistical ensemble, often denoted by the set $\{(p_{k},|\Psi_{k}\rangle)\}$. When we measure an observable $F$, the possible outcomes are still restricted to the spectrum $\sigma(F)$. However, we must modify the overall probability $\mathbb{P}(\lambda)$ of observing a specific outcome $\lambda\in\sigma(F)$ to account for the classical uncertainty in the preparation.

Law of Total Probability: Using classical probability theory, the total probability of measuring $\lambda\in\sigma(F)$, for an observable $F:\mathcal{H}\rightarrow\mathcal{H}$, is the sum of the conditional probabilities of measuring $\lambda$ given a specific state $|\Psi_{k}\rangle$, weighted by the probability $p_{k}$ of being in that state:

$\mathbb{P}(\lambda)=\sum_{k}\mathbb{P}(\lambda\mid\Psi_{k})\cdot p_{k}$

We know from our previous postulates that the probability of outcome $\lambda$ given the pure state $|\Psi_{k}\rangle$ is $\mathbb{P}_{\Psi_{k}}(\lambda)=\langle\Psi_{k}|\,P_{\lambda}\,|\Psi_{k}\rangle$. Substituting this into our equation yields:

$\mathbb{P}(\lambda)=\sum_{k}p_{k}\,\langle\Psi_{k}|\,P_{\lambda}\,|\Psi_{k}\rangle$

The Density Operator: To represent this statistical ensemble of pure states compactly, we introduce the density operator/matrix (or mixed state ) $\rho$, defined as:

$\rho=\sum_{k}p_{k}\,|\Psi_{k}\rangle\,\langle\Psi_{k}|$

Using this operator, we can rewrite the probability $\mathbb{P}(\lambda)$ using the trace operation. Let us verify this relationship:

$\mathrm{tr}(\rho P_{\lambda})$ $=\mathrm{tr}\left(\left(\sum_{k}p_{k}\,|\Psi_{k}\rangle\,\langle\Psi_{k}|\right)P_{\lambda}\right)$  
$=\sum_{k}p_{k}\,\mathrm{tr}\Big{(}\,|\Psi_{k}\rangle\,\langle\Psi_{k}|\,P_{\lambda}\Big{)}=\sum_{k}p_{k}\,\langle\Psi_{k}|\,P_{\lambda}\,|\Psi_{k}\rangle$

Thus, we arrive at the elegant conclusion that the probability of measuring $\lambda$ for a mixed state $\rho$ is simply:

$\mathbb{P}_{\rho}(\lambda):=\mathrm{tr}(\rho P_{\lambda})$

For an observable $F$, the expected value $\langle F\rangle_{\rho}$ is the sum of all possible outcomes

---

weighted by their probability:

$$
\begin{array}{l}
\langle F \rangle_{\rho} = \sum_{\lambda \in \sigma(F)} \lambda \cdot \mathbb{P}_{\rho}(\lambda) \\
= \sum_{\lambda \in \sigma(F)} \lambda \cdot \operatorname{tr}(\rho P_{\lambda}) \\
= \operatorname{tr}\left(\rho \sum_{\lambda \in \sigma(F)} \lambda P_{\lambda}\right) = \operatorname{tr}(\rho F)
\end{array}
$$

## Post-Measurement State of an Ensemble

Suppose we measure an observable $F$ on a mixed state $\rho$ and obtain the result $\lambda \in \sigma(F)$. What is the state of the quantum system immediately after this measurement? If the system was originally in state $|\Psi_k\rangle$ (which occurs with probability $p_k$), the measurement of $\lambda$ collapses it to a new normalized state:

$$
|\phi_k\rangle = \frac{P_{\lambda} |\Psi_k\rangle}{\|P_{\lambda} \Psi_k\|}
$$

To find the new mixed state, we must determine the updated probability $q_k$ that the system was in state $|\Psi_k\rangle$ given that the outcome $\lambda$ was observed. We use classical probability and Bayes' Theorem:

$$
\begin{array}{l}
q_k = \mathbb{P}(\text{was in } \Psi_k \mid \text{result is } \lambda) = \frac{\mathbb{P}(\text{result is } \lambda \mid \text{was in } \Psi_k) \cdot \mathbb{P}(\text{was in } \Psi_k)}{\mathbb{P}(\text{result is } \lambda)} \\
= \frac{\mathbb{P}_{\Psi_k}(\lambda) \cdot p_k}{\mathbb{P}_{\rho}(\lambda)} \\
= \frac{p_k \langle\Psi_k \mid P_{\lambda} \mid\Psi_k \rangle}{\operatorname{tr}(P_{\lambda} \rho)}
\end{array}
$$

The state after the measurement is an ensemble of the collapsed states $|\phi_k\rangle$ with the updated probabilities $q_k$. We can construct the new density matrix $\rho_{\mathrm{after}}$:

$$
\rho_{\mathrm{after}} = \sum_k q_k |\phi_k\rangle \langle\phi_k|
$$

Substituting $q_k$ and $|\phi_k\rangle$ into this sum, we get:

$$
\sum_k \left( \frac{p_k \langle\Psi_k \mid P_{\lambda} \mid\Psi_k \rangle}{\operatorname{tr}(P_{\lambda} \rho)} \right) \left( \frac{P_{\lambda} \mid\Psi_k \rangle \langle\Psi_k \mid P_{\lambda}}{\langle\Psi_k \mid P_{\lambda} \mid\Psi_k \rangle} \right) = \frac{P_{\lambda} \left( \sum_k p_k \mid\Psi_k \rangle \langle\Psi_k \right) \mid P_{\lambda}}{\operatorname{tr}(P_{\lambda} \rho)} = \frac{P_{\lambda} \rho P_{\lambda}}{\operatorname{tr}(P_{\lambda} \rho)}
$$

## Properties of the Density Operator

Let $\mathcal{D}(\mathcal{H})$ denote the set of all mixed states (density operators) on the Hilbert space $\mathcal{H}$. Recall that a mixed state formally describes a statistical ensemble of

---

pure states, $\{(p_{k},|\Psi_{k}\rangle)\}$, accounting for the classical uncertainty in the system’s preparation. A valid density operator $\rho\in\mathcal{D}(\mathcal{H})$ representing such an ensemble must satisfy the following fundamental properties:

1. Unit Trace: The probabilities of the ensemble must sum to 1.

$\mathrm{tr}(\rho)=\mathrm{tr}\left(\sum_{k}p_{k}\left|\Psi_{k}\right\rangle\left\langle\Psi_{k}\right|\right)=\sum_{k}p_{k}=1$  
2. Positive Semi-Definiteness ($\rho\geq 0$): For any arbitrary vector $\left|\varphi\right\rangle\in\mathcal{H}$, the expectation value must be non-negative.

$\left\langle\varphi\right|\rho\left|\varphi\right\rangle=\left\langle\varphi\right|\left(\sum_{k}p_{k}\left|\Psi_{k}\right\rangle\left\langle\Psi_{k}\right|\right)\left|\varphi\right\rangle=\sum_{k}p_{k}\left|\left\langle\varphi|\Psi_{k}\right\rangle\right|^{2}\geq 0$

Since $p_{k}\geq 0$ and the absolute square is non-negative, the sum is strictly $\geq 0$.  
3. Observational Equivalence: The density matrix contains all accessible physical information about the system. If two density matrices $\rho_{1}$ and $\rho_{2}$ yield the same expected values for all possible observables, they represent the exact same state. That is, if for every Hermitian operator $F\in L(\mathcal{H})$:

$\left\langle F\right\rangle_{\rho_{1}}=\left\langle F\right\rangle_{\rho_{2}}\implies\mathrm{tr}(\rho_{1}F)=\mathrm{tr}(\rho_{2}F)\implies\rho_{1}=\rho_{2}$

This final implication follows directly from the fact that the set of Hermitian matrices forms a real Hilbert space equipped with the Hilbert-Schmidt inner product, defined as $\left\langle A,B\right\rangle_{HS}=\mathrm{tr}(AB)$. The equation $\mathrm{tr}((\rho_{1}-\rho_{2})F)=0$ means that the matrix $(\rho_{1}-\rho_{2})$ is orthogonal to every element $F$ in the entire space of Hermitian matrices. Since the only element perpendicular to all elements in an inner product space is the zero element itself, it must be that $\rho_{1}-\rho_{2}=0$, and therefore $\rho_{1}=\rho_{2}$.

If we are given any positive semi-definite matrix $\rho\geq 0$ with unit trace ($\mathrm{tr}(\rho)=1$), it mathematically guarantees the existence of a corresponding statistical ensemble. By the spectral theorem, since $\rho$ is Hermitian, we can always diagonalize it to find its canonical ensemble:

$\rho=\sum_{k=1}^{d}\lambda_{k}\left|e_{k}\right\rangle\left\langle e_{k}\right|$

where $\{\left|e_{k}\right\rangle\}_{k=1}^{d}$ forms an orthonormal basis (ONB) of $\mathcal{H}$, and the eigenvalues $\lambda_{k}$ form a valid probability distribution (i.e., $\lambda_{k}\geq 0$ and $\sum_{k}\lambda_{k}=1$).

Fact (Convexity of Density Matrices). The set of all valid mixed states, $\mathcal{D}(\mathcal{H})$, forms a convex set. If we take any collection of density matrices $\rho_{1},\rho_{2},\ldots,\rho_{n}\in\mathcal{D}(\mathcal{H})$

---

and mix them with classical probabilities $p_{1},\ldots,p_{\alpha}>0$ (where $\sum_{k=1}^{n}p_{k}=1$), the resulting convex combination

$\rho=\sum_{k=1}^{n}p_{k}\rho_{k}$

is also a valid state in $\mathcal{D}(\mathcal{H})$.

###### Proof.

To show that $\rho\in\mathcal{D}(\mathcal{H})$, we must verify the two defining properties of a density matrix: it must have unit trace and be positive semi-definite.

1. Trace: By the linearity of the trace operation,

$\mathrm{tr}(\rho)=\mathrm{tr}\left(\sum_{k=1}^{n}p_{k}\rho_{k}\right)=\sum_{k=1}^{n}p_{k}\,\mathrm{tr}(\rho_{k})$

Since each $\rho_{k}$ is a valid density matrix, $\mathrm{tr}(\rho_{k})=1$. Thus, $\sum_{k=1}^{n}p_{k}(1)=1$.  
2. Positivity: For any arbitrary state vector $\ket{\Psi}\in\mathcal{H}$,

$\bra{\Psi}\rho\ket{\Psi}=\bra{\Psi}\left(\sum_{k=1}^{n}p_{k}\rho_{k}\right)\ket{\Psi}=\sum_{k=1}^{n}p_{k}\bra{\Psi}\rho_{k}\ket{\Psi}$

Because each $\rho_{k}$ is positive semi-definite, $\bra{\Psi}\rho_{k}\ket{\Psi}\geq 0$. Since the probabilities $p_{k}$ are also positive, the entire sum is non-negative, meaning $\rho\geq 0$.

Since $\rho$ satisfies both conditions, $\rho\in\mathcal{D}(\mathcal{H})$, concluding the proof that the set is convex. ∎

A pure state is simply an extreme point of this convex set—a state that cannot be written as a mixture of other states. It is represented by a rank-1 orthogonal projection onto a state vector: $\rho=\ket{\Psi}\bra{\Psi}$. We can determine if an arbitrary state $\rho$ is pure without finding its eigendecomposition by using the trace of its square:

###### Theorem.

A density matrix $\rho$ represents a pure state if and only if $\text{tr}(\rho)=\text{tr}(\rho^{2})$.

###### Proof.

$(\implies)$ If $\rho$ is pure, $\rho=\ket{\Psi}\bra{\Psi}$. Then $\rho^{2}=\ket{\Psi}\bra{\Psi}\ket{\Psi}\bra{\Psi}=\ket{\Psi}\bra{\Psi}=\rho$. Therefore, $\text{tr}(\rho^{2})=\text{tr}(\rho)=1$.

$(\Leftarrow)$ Suppose $\text{tr}(\rho)=\text{tr}(\rho^{2})$. Using the canonical spectral decomposition $\rho=\sum_{k=1}^{d}\lambda_{k}\ket{e_{k}}\bra{e_{k}}$, we evaluate the difference:

$0=\text{tr}(\rho-\rho^{2})$ $=\sum_{k=1}^{d}\bra{e_{k}}\rho-\rho^{2}\ket{e_{k}}$  
$=\sum_{k=1}^{d}(\lambda_{k}-\lambda_{k}^{2})$  
$=\sum_{k=1}^{d}\lambda_{k}(1-\lambda_{k})$

---

Since $\rho \geq 0$, every eigenvalue $\lambda_k \geq 0$. Because their sum is 1, we must have $\lambda_k \leq 1$. Therefore, every term $\lambda_k(1 - \lambda_k)$ in the sum is non-negative. For the sum to be identically zero, every individual term must be zero, meaning $\forall k$, either $\lambda_k = 0$ or $\lambda_k = 1$. Since $\operatorname{tr}(\rho) = \sum \lambda_k = 1$, exactly one eigenvalue can be 1 and the rest must be 0. This implies $\rho$ is a rank-1 projector, hence a pure state.

For a fixed $\rho \geq 0$, $\operatorname{tr}(\rho) = 1$ there are many ensembles $\{|\varphi_i\rangle, p_i\}$ for which

$$
\rho = \sum_{i=1}^{m} p_i |\varphi_i\rangle \langle\varphi_i|
$$

**Theorem (Unitary Freedom in the Ensemble).**  Let $\rho$ be a mixed state with spectral decomposition

$$
\rho = \sum_{k=1}^{n} \lambda_k |e_k\rangle \langle e_k| \quad n \leq d, \quad \mathcal{H} = \mathbb{C}^d
$$

Then

$$
\rho = \sum_{i=1}^{m} p_i |\psi_i\rangle \langle\psi_i| \iff \begin{array}{l}
1) \, m \geq n \\
2) \, \exists U \in \mathcal{U}(m) \, \text{s.t.} \\
\sqrt{p_i} |\psi_i\rangle = \sum_{j=1}^{n} U_{ij} \sqrt{\lambda_j} |e_j\rangle \quad \forall i \in \{1, \ldots, m\}
\end{array}
$$

**Proof (**​**$\Leftarrow$**​ **).**

$$
\begin{aligned}
\sum_{i=1}^{m} p_i |\psi_i\rangle \langle\psi_i| &= \sum_{i=1}^{m} \left( \sum_{j=1}^{n} U_{ij} \sqrt{\lambda_j} |e_j\rangle \right) \left( \sum_{k=1}^{n} \overline{U}_{ik} \sqrt{\lambda_k} \langle e_k | \right) \\
&= \sum_{i=1}^{m} \sum_{j=1}^{n} \sum_{k=1}^{n} \sqrt{\lambda_j \lambda_k} U_{ij} \overline{U}_{ik} |e_j\rangle \langle e_k | \\
&= \sum_{j,k=1}^{n} \sqrt{\lambda_j \lambda_k} \underbrace{\left( \sum_{i=1}^{m} U_{ij} \overline{U}_{ik} \right)}_{\delta_{jk}} |e_j\rangle \langle e_k | \\
&= \sum_{k=1}^{n} \lambda_k |e_k\rangle \langle e_k | \quad \square
\end{aligned}
$$

**Definition.**  von Neumann entropy of state $\rho$ is

$$
\begin{aligned}
S(\rho) = -\operatorname{tr}(\rho \log(\rho)) &= -\sum_{k=1}^{d} \lambda_k \log \lambda_k \\
S(\rho) = 0 &\iff \rho \text{ is a pure state}
\end{aligned}
$$

---

For maximally mixed state $\rho_{M} = \frac{1}{d}\mathbb{I},\quad S(\rho_{M}) = \log (d)$. Free time evolution of $\rho$ is again unitary, $\{|\psi_k\rangle ,p_k\}$

$$
\rho (t) = \sum_ {k} p _ {k} | \psi_ {k} (t) \rangle \langle \psi_ {k} (t) | = U (t, t _ {0}) ^ {\dagger} \rho (t _ {0}) U (t, t _ {0})
$$

$$
| \psi_ {k} (t) \rangle = U (t, t _ {0}) | \psi_ {k} (t _ {0}) \rangle
$$

# 3 Systems with subsystems

Assume we have $N$ quantum systems described by Hilbert spaces $\mathcal{H}_1, \ldots, \mathcal{H}_N$. Let the total composite system be denoted as $\mathcal{H}$.

- If systems $\mathcal{H}_1, \ldots, \mathcal{H}_N$ are **distinguishable** then

$$
\mathcal {H} = \mathcal {H} _ {1} \otimes \mathcal {H} _ {2} \otimes \dots \otimes \mathcal {H} _ {N}
$$

- If systems $\mathcal{H}_1, \ldots, \mathcal{H}_N$ are **indistinguishable** (and $\dim(\mathcal{H}_k) = d \ \forall k$):
- Fermionic: $\mathcal{H} = \bigwedge^{N}\mathbb{C}^{d}$
- Bosonic: $\mathcal{H} = \bigvee^{N}\mathbb{C}^{d}$

We will focus mostly on the distinguishable case.

If the quantum system is in the pure state $|\Psi \rangle \in \mathcal{H} = \mathcal{H}_1\otimes \dots \otimes \mathcal{H}_N$ what are the states of the individual subsystems $QS_{1},\ldots ,QS_{N}$? Let's start with $N = 2$

# 3.1 $N = 2$

- If $|\Psi \rangle = |\psi_1\rangle \otimes |\psi_2\rangle \in \mathcal{H}$ is a **simple tensor**, then the subsystems $QS_{1}$ and $QS_{1}$ are in the states $|\psi_1\rangle$ and $|\psi_2\rangle$ respectively. We say $|\Psi \rangle$ is **separable** or **not entangled**.
- In general $(N = 2)$, let $\mathcal{H}_1 = \operatorname{Span}\{|e_1\rangle, \ldots, |e_{d_1}\rangle\}$ and $\mathcal{H}_2 = \operatorname{Span}\{|f_1\rangle, \ldots, |f_{d_2}\rangle\}$. Then

$$
| \Psi \rangle = \sum_ {i = 1} ^ {d _ {1}} \sum_ {j = 1} ^ {d _ {2}} C _ {i j} | e _ {i} \rangle \otimes | f _ {j} \rangle
$$

To determine states of $QS_{1}$ and $QS_{2}$ we consider (Lie) **algebras of observables**. Let $F_{1} \in L_{sa}(\mathcal{H}_{1})$ and $F_{2} \in L_{sa}(\mathcal{H}_{2})$ be observables for subsystems 1 and 2. They embed into the total system as:

$$
L _ {s a} (\mathcal {H} _ {1}) \hookrightarrow L _ {s a} (\mathcal {H} _ {1} \otimes \mathcal {H} _ {2}) \quad F _ {1} \mapsto F _ {1} \otimes I _ {d _ {2}}
$$

$$
L _ {s a} (\mathcal {H} _ {2}) \hookrightarrow L _ {s a} (\mathcal {H} _ {1} \otimes \mathcal {H} _ {2}) \quad F _ {2} \mapsto I _ {d _ {1}} \otimes F _ {2}
$$

The state of a system is determined by all expected values of its observables:

$$
\langle F _ {1} \rangle_ {\rho^ {(1)}} = \langle F _ {1} \otimes I _ {d _ {2}} \rangle_ {| \Psi \rangle} \Rightarrow \operatorname {t r} \left(\rho^ {(1)} F _ {1}\right) = \langle \Psi | F _ {1} \otimes I _ {d _ {2}} | \Psi \rangle
$$

$$
\langle F _ {2} \rangle_ {\rho^ {(2)}} = \langle I _ {d _ {1}} \otimes F _ {2} \rangle_ {| \Psi \rangle} \Rightarrow \operatorname {t r} \left(\rho^ {(2)} F _ {2}\right) = \langle \Psi | I _ {d _ {1}} \otimes F _ {2} | \Psi \rangle
$$

---

To find the explicit form of $\rho^{(1)}$, let us compute the right-hand side of the first equation. Substituting $|\Psi\rangle=\sum_{i,j}C_{ij}|e_i\rangle\otimes|f_j\rangle$:

$$
\begin{aligned}
\langle\Psi| F_1 \otimes I_{d_2}|\Psi\rangle &= \left(\sum_{k=1}^{d_1} \sum_{l=1}^{d_2} \overline{C}_{kl} \langle e_k| \otimes \langle f_l|\right) (F_1 \otimes I_{d_2}) \left(\sum_{i=1}^{d_1} \sum_{j=1}^{d_2} C_{ij}|e_i\rangle \otimes |f_j\rangle\right) \\
&= \sum_{i,k=1}^{d_1} \sum_{j,l=1}^{d_2} \overline{C}_{kl} C_{ij} \langle e_k| F_1|e_i\rangle \underbrace{\langle f_l| I_{d_2} |f_j \rangle}_{\delta_{ij}} \\
&= \sum_{i,k=1}^{d_1} \sum_{j=1}^{d_2} C_{ij} \overline{C}_{kj} \langle e_k| F_1|e_i\rangle \\
&= \sum_{i,k=1}^{d_1} \left(\sum_{j=1}^{d_2} C_{ij} \overline{C}_{kj}\right) \langle e_k| F_1|e_i\rangle
\end{aligned}
$$

On the left-hand side, since $\mathrm{tr}\big(\rho^{(1)}F_1\big) = \sum_{i,k=1}^{d_1}\langle e_i|\rho^{(1)}|e_k\rangle \langle e_k|F_1|e_i\rangle$, we can match the terms to deduce the matrix elements of $\rho^{(1)}$:

$$
\langle e_i|\rho^{(1)}|e_k\rangle = \sum_{j=1}^{d_2} C_{ij} \overline{C}_{kj} = (CC^\dagger)_{ik}
$$

Therefore, the reduced state of the first subsystem is:

$$
\rho^{(1)} = \mathrm{tr}_2(|\Psi\rangle \langle\Psi|) = \sum_{i,k=1}^{d_1} (CC^\dagger)_{ik} |e_i\rangle \langle e_k| = CC^\dagger
$$

Similarly, for the second subsystem $\rho^{(2)}$, we evaluate the expectation value of $I_{d_1} \otimes F_2$:

$$
\begin{aligned}
\langle\Psi| I_{d_1} \otimes F_2|\Psi\rangle &= \sum_{i,k=1}^{d_1} \sum_{j,l=1}^{d_2} \overline{C}_{kl} C_{ij} \underbrace{\langle e_k| I_{d_1} |e_i\rangle}_{\delta_{ki}} \langle f_l| F_2|f_j\rangle \\
&= \sum_{i=1}^{d_1} \sum_{j,l=1}^{d_2} C_{ij} \overline{C}_{il} \langle f_l| F_2|f_j\rangle \\
&= \sum_{j,l=1}^{d_2} \left(\sum_{i=1}^{d_1} C_{ij} \overline{C}_{il}\right) \langle f_l| F_2|f_j\rangle
\end{aligned}
$$

Matching this with $\mathrm{tr}\big(\rho^{(2)}F_2\big) = \sum_{j,l=1}^{d_2}\langle f_j|\rho^{(2)}|f_l\rangle \langle f_l|F_2|f_j\rangle$, we get the matrix elements for $\rho^{(2)}$:

$$
\langle f_j|\rho^{(2)}|f_l\rangle = \sum_{i=1}^{d_1} C_{ij} \overline{C}_{il} = \sum_{i=1}^{d_1} (C^T)_{ji} (\overline{C})_{il} = (C^T \overline{C})_{jl}
$$

---

Thus, the reduced state of the second subsystem is:

$$
\rho^{(2)} = \operatorname{tr}_1(|\Psi\rangle\langle\Psi|) = \sum_{j,l=1}^{d_2}(C^T\overline{C})_{jl} |f_j\rangle\langle f_l| = C^T\overline{C}
$$

## 3.2 General Case

- $\mathcal{H} = \mathcal{H}_1 \otimes \mathcal{H}_2 \otimes \cdots \otimes \mathcal{H}_N \cong \mathbb{C}^{d_1} \otimes \mathbb{C}^{d_2} \otimes \cdots \otimes \mathbb{C}^{d_N}$
- Choose an ONB in $\mathcal{H}_k$: $|0\rangle, |1\rangle, \ldots, |d_k - 1\rangle$.
- Basis of $\mathcal{H}$: $|i_1\rangle \otimes |i_2\rangle \otimes \cdots \otimes |i_N\rangle = |i_1 i_2 \ldots i_N\rangle$, where $i_k \in \{0, \ldots, d_k - 1\}$.
- Let $\rho \in \mathcal{D}(\mathcal{H})$ be a general mixed state of the total composite system.
- $L_{sa}(\mathcal{H}_1 \otimes \cdots \otimes \mathcal{H}_N)$ – observables of system $\mathcal{H}$ (self-adjoint).

Embed subsystem observables into the total system:

$$
L_{sa}(\mathcal{H}_k) \hookrightarrow L_{sa}(\mathcal{H}_1 \otimes \cdots \otimes \mathcal{H}_N)
$$

$$
L_{sa}(\mathcal{H}_k) \ni F_k \mapsto \underbrace{I \otimes \cdots \otimes I}_{k-1} \otimes F_k \otimes \underbrace{I \otimes \cdots \otimes I}_{N-k} = \tilde{F}_k
$$

The state of a system is determined by all expected values of observables. We look for $\rho^{(k)} \in \mathcal{D}(\mathcal{H}_k)$ such that:

$$
\langle F_k \rangle_{\rho^{(k)}} = \langle \tilde{F}_k \rangle_\rho
$$

Since $L_{sa}(\mathcal{H}_k)$ is a real Hilbert space with the inner product $(F, G)_{HS} = \mathrm{tr}(FG)$, and $\langle \tilde{F}_k \rangle_\rho = \mathrm{tr}\left(\rho \tilde{F}_k\right)$ is a linear functional on $L_{sa}(\mathcal{H}_k)$, there is a unique self-adjoint matrix $\rho^{(k)}$ such that:

$$
\operatorname{tr}\left(\rho^{(k)} F_k\right) = \operatorname{tr}\left(\rho \tilde{F}_k\right)
$$

Let us compute both sides explicitly to find the matrix elements of $\rho^{(k)}$. For the right-hand side, we insert the resolution of the identity $I = \sum |j_1 \ldots j_N\rangle \langle j_1 \ldots j_N|$:

$$
\begin{aligned}
\operatorname{tr}\left(\rho \tilde{F}_k\right) &= \sum_{i_1 \ldots i_N} \langle i_1 \ldots i_N | \rho \tilde{F}_k | i_1 \ldots i_N \rangle \\
&= \sum_{\substack{i_1 \ldots i_N \\ j_1 \ldots j_N}} \langle i_1 \ldots i_N | \rho | j_1 \ldots j_N \rangle \langle j_1 \ldots j_N | I \cdots \otimes F_k \otimes \ldots I | i_1 \ldots i_N \rangle
\end{aligned}
$$

Since $\tilde{F}_k$ acts only on the $k$-th subsystem, the matrix element $\langle j_1 \ldots j_N | \tilde{F}_k | i_1 \ldots i_N \rangle$ is non-zero only when all indices except the $k$-th one match. Thus:

$$
\langle j_1 \ldots j_N | \tilde{F}_k | i_1 \ldots i_N \rangle = \delta_{j_1, i_1} \ldots \langle j_k | F_k | i_k \rangle \ldots \delta_{j_N, i_N}
$$

---

Substituting this back, the sums over all $j_{m}$ (for $m \neq k$) collapse:

$$
\begin{array}{l}
\operatorname{tr}\left(\rho \hat{F}_{k}\right) = \sum_{i_{1} \dots i_{N}} \sum_{j_{k}} \langle i_{1} \dots i_{k} \dots i_{N} | \rho | i_{1} \dots j_{k} \dots i_{N} \rangle \langle j_{k} | F_{k} | i_{k} \rangle \\
= \sum_{i_{k}, j_{k}} \left(\sum_{i_{1} \dots i_{k} \dots i_{N}} \langle i_{1} \dots i_{k} \dots i_{N} | \rho | i_{1} \dots j_{k} \dots i_{N} \rangle\right) \langle j_{k} | F_{k} | i_{k} \rangle
\end{array}
$$

On the other hand, evaluating the left-hand side directly in the basis of $\mathcal{H}_k$:

$$
\begin{array}{l}
\operatorname{tr}\left(\rho^{(k)} F_{k}\right) = \sum_{i_{k}} \langle i_{k} | \rho^{(k)} F_{k} | i_{k} \rangle \\
= \sum_{i_{k}, j_{k}} \langle i_{k} | \rho^{(k)} | j_{k} \rangle \langle j_{k} | F_{k} | i_{k} \rangle
\end{array}
$$

Matching the terms multiplying the arbitrary observable elements $\langle j_k|F_k|i_k\rangle$, we uniquely determine the matrix elements of $\rho^{(k)}$:

$$
\langle i_{k} | \rho^{(k)} | j_{k} \rangle = \sum_{i_{1} \dots i_{k} \dots i_{N}} \langle i_{1} \dots i_{k} \dots i_{N} | \rho | i_{1} \dots j_{k} \dots i_{N} \rangle
$$

We define this operation as the **partial trace** over all subsystems except $k$:

$$
\rho^{(k)} = \operatorname{tr}_{1, \dots , k - 1, k + 1, \dots , N}(\rho) = \sum \rho_{i_{1} \dots i_{k} \dots i_{N}, i_{1} \dots j_{k} \dots i_{N}} | i_{k} \rangle \langle j_{k} |
$$

For a bipartite system $\mathcal{H} = \mathcal{H}_1 \otimes \mathcal{H}_2$, we have:

$$
\rho^{(1)} = \operatorname{tr}_{2}(\rho) = \sum_{k = 0}^{d_{2} - 1} \rho_{i_{k}, j_{k}} | i \rangle \langle j |
$$

$$
\rho^{(2)} = \operatorname{tr}_{1}(\rho) = \sum_{k = 0}^{d_{1} - 1} \rho_{k i, k j} | i \rangle \langle j |
$$

**Reduction of a Pure State:**

Now, assume the total system is in a pure state, represented by the projection operator $\rho = |\Psi\rangle \langle\Psi|$. Let the state vector be:

$$
|\Psi\rangle = \sum_{i_{1} = 0}^{d_{1} - 1} \dots \sum_{i_{N} = 0}^{d_{N} - 1} C_{i_{1} \dots i_{N}} | i_{1} \dots i_{N} \rangle
$$

The matrix elements of the density operator $\rho$ are simply:

$$
\langle i_{1} \dots i_{k} \dots i_{N} | \rho | i_{1} \dots j_{k} \dots i_{N} \rangle = C_{i_{1} \dots i_{k} \dots i_{N}} \overline{C}_{i_{1} \dots j_{k} \dots i_{N}}
$$

Substituting this into our derived formula for the partial trace, the matrix elements of the reduced state become:

$$
(\rho^{(k)})_{i_{k}, j_{k}} = \sum_{i_{1} \dots i_{k} \dots i_{N}} C_{i_{1} \dots i_{k} \dots i_{N}} \overline{C}_{i_{1} \dots j_{k} \dots i_{N}}
$$

---

Hence, the reduced density matrix for subsystem $k$ when the total system is in pure state $|\Psi\rangle$ is explicitly:

$$
\rho^{(k)} = \sum_{i_k, j_k} \left( \sum_{i_1, \dots, i_k, \dots, i_N} C_{i_1, \dots, i_k, \dots, i_N} \overline{C}_{i_1, \dots, j_k, \dots, i_N} \right) |i_k\rangle \langle j_k|
$$

Example: Assume $|\Psi\rangle = |\psi_1\rangle \otimes \cdots \otimes |\psi_N\rangle$. Show that $\rho^{(1)} = |\psi_1\rangle \langle \psi_1|$, $\rho^{(2)} = |\psi_2\rangle \langle \psi_2|$, ..., $\rho^{(N)} = |\psi_N\rangle \langle \psi_N|$.

## 4 Schmidt normal form

**Fact.**  Let $F: \mathcal{H} \to \mathcal{H}$. Then

1. $\ker(F) = \ker(F^\dagger F)$, and $\ker(F^\dagger) = \ker(FF^\dagger)$.
2. $\sigma(FF^\dagger) = \sigma(F^\dagger F)$, and multiplicities are the same.

**Proof.**  1) Obviously $\ker(F) \subset \ker(F^\dagger F)$. Assume $v \in \ker(F^\dagger F)$. Then $F^\dagger Fv = 0$. This implies:

$$
\begin{array}{l}
\langle v | F^\dagger F v \rangle = 0 \Longrightarrow \langle F v | F v \rangle = 0 \\
\Longrightarrow | | F v | | = 0 \\
\Longrightarrow F v = 0 \Longrightarrow v \in \ker(F).
\end{array}
$$

Hence $\ker(F^\dagger F) \subset \ker(F)$. The same argument gives $\ker(F^\dagger) = \ker(FF^\dagger)$.

2. For non-zero eigenvalues ($\lambda \neq 0$):

$$
\begin{array}{l}
0 \neq \lambda \in \sigma(F^\dagger F) \Longrightarrow \exists v, F^\dagger F v = \lambda v \\
\Longrightarrow F F^\dagger(F v) = \lambda(F v) \\
\Longrightarrow F v \in \ker(FF^\dagger - \lambda I) \Longrightarrow \lambda \in \sigma(FF^\dagger)
\end{array}
$$

Similarly:

$$
\begin{array}{l}
0 \neq \lambda \in \sigma(FF^\dagger) \Longrightarrow \exists v, F F^\dagger v = \lambda v \\
\Longrightarrow F^\dagger F (F^\dagger v) = \lambda (F^\dagger v) \\
\Longrightarrow F^\dagger v \in \ker(F^\dagger F - \lambda I) \Longrightarrow \lambda \in \sigma(F^\dagger F)
\end{array}
$$

Let $v_1, \ldots, v_k$ be a basis of $\ker(F^\dagger F - \lambda I)$. Then $Fv_1, \ldots, Fv_k \in \ker(FF^\dagger - \lambda I)$. We show $Fv_1, \ldots, Fv_k$ are linearly independent. Assume not. Then $\exists \alpha_1, \ldots, \alpha_k$ not all zero s.t.

$$
\begin{array}{l}
\alpha_1 F v_1 + \cdots + \alpha_k F v_k = 0 \\
\Longrightarrow F \underbrace{\left( \alpha_1 v_1 + \cdots + \alpha_k v_k \right)}_{\neq 0} = 0 \\
\Longrightarrow \alpha_1 v_1 + \cdots + \alpha_k v_k \in \ker(F).
\end{array}
$$

---

This implies $\alpha_{1}v_{1}+\dots+\alpha_{k}v_{k}\in\ker(F^{\dagger}F)$, which is a contradiction since it corresponds to an eigenvector for $\lambda\neq 0$.

When $\lambda=0$, we look at the dimensions:

$\dim\ker(FF^{\dagger})$ $=\dim\ker(F^{\dagger})$  
$=\dim(\operatorname{Im}F)^{\perp}$  
$=\dim(\mathcal{H})-\dim(\operatorname{Im}F)$  
$=\dim\ker(F)$  
$=\dim\ker(F^{\dagger}F)$ $\square$

Conclusion: There are unitary matrices $U,V$ such that $U[FF^{\dagger}]U^{\dagger}=D=V[F^{\dagger}F]V^{\dagger}$, where $D$ is a diagonal matrix with non-negative eigenvalues.

### 4.1 Local unitary action

We focus next on a particular system $\mathcal{H}=\mathcal{H}_{1}\otimes\mathcal{H}_{2}$ where $\mathcal{H}_{1}\cong\mathbb{C}^{d}\cong\mathcal{H}_{2}$.

$|\Psi\rangle=\sum_{i=1}^{d}\sum_{j=1}^{d}C_{ij}|i\rangle\otimes|j\rangle$

The reduced density matrices are computed as:

$\rho_{1}=\operatorname{tr}_{2}(|\Psi\rangle\langle\Psi|)=\sum_{i,j,k}C_{ik}\overline{C}_{jk}|i\rangle\langle j|=\sum_{i,j,k}C_{ik}(\bar{C}^{T})_{kj}|i\rangle\langle j|=\sum_{i,j}(CC^{\dagger})_{ij}|i\rangle\langle j|=CC^{\dagger}$  
$\rho_{2}=\operatorname{tr}_{1}(|\Psi\rangle\langle\Psi|)=\sum_{i,j,k}C_{ki}\overline{C}_{kj}|i\rangle\langle j|=\sum_{i,j,k}C_{ik}^{T}\bar{C}_{kj}|i\rangle\langle j|=\sum_{i,j}(C^{T}\bar{C})_{ij}|i\rangle\langle j|=C^{T}\bar{C}$

What happens when we act on $|\Psi\rangle$ with local unitary operations $U\otimes V$ where $U,V\in\mathcal{U}(d)$? How do $\rho^{(1)}$ and $\rho^{(2)}$ change? Let $|\bar{\Psi}\rangle=U\otimes V|\Psi\rangle$.

$U\otimes V|\Psi\rangle$ $=\sum_{i=1}^{d}\sum_{j=1}^{d}C_{ij}U|i\rangle\otimes V|j\rangle=\sum_{i,j}C_{ij}\Big{(}\sum_{k}U_{ki}|k\rangle\Big{)}\otimes\Big{(}\sum_{m}V_{mj}|m\rangle\Big{)}$  
$=\sum_{i,j,k,m}U_{ki}C_{ij}V_{mj}|k\rangle\otimes|m\rangle=\sum_{k,j,m}U_{ki}C_{ij}(V^{T})_{jm}|k\rangle\otimes|m\rangle$  
$=\sum_{k,m}(UCV^{T})_{km}|k\rangle\otimes|m\rangle=\sum_{k,m}M_{km}|k\rangle\otimes|m\rangle$

---

The updated reduced states become:

$\tilde{\rho}_{1}$ $=\mathrm{tr}_{2}(|\tilde{\Psi}\rangle\langle\tilde{\Psi}|)$  
$=\sum_{i,j}(MM^{\dagger})_{ij}|i\rangle\langle j|$  
$=\sum_{i,j}(UCV^{T}\cdot\bar{V}C^{\dagger}U^{\dagger})_{ij}|i\rangle\langle j|$  
$=\sum_{i,j}(UCC^{\dagger}U^{\dagger})_{ij}|i\rangle\langle j|$  
$=U\rho_{1}U^{\dagger}$  
$\tilde{\rho}_{2}$ $=\mathrm{tr}_{1}(|\tilde{\Psi}\rangle\langle\tilde{\Psi}|)$  
$=\sum_{i,j}(M^{T}\overline{M})_{ij}|i\rangle\langle j|$  
$=\sum_{i,j}((UCV^{T})^{T}\cdot\overline{UCV^{T}})_{ij}|i\rangle\langle j|$  
$=\sum_{i,j}(VC^{T}\underbrace{U^{T}\bar{U}}_{I}\bar{C}V^{\dagger})_{ij}|i\rangle\langle j|$  
$=\sum_{i,j}(VC^{T}\bar{C}V^{\dagger})_{ij}|i\rangle\langle j|$  
$=V\rho_{2}V^{\dagger}$

So under local unitary evolutions subsystems are transformed independently.

Next we show that we can choose matrices $U,V$ such that $M$, $\rho_{1}$ and $\rho_{2}$ are simultaneously diagonal. The matrices

$CC^{\dagger}\qquad\text{and}\qquad C^{\dagger}C$

are positive Hermitian. By Fact 4 we may choose unitaries $U,V\in U(d)$ such that

$UCC^{\dagger}U^{\dagger}=D,\qquad\overline{V}\,C^{\dagger}C\,V^{T}=D,$

where

$D=\mathrm{diag}(p_{1},\ldots,p_{d}),\qquad p_{i}\geq 0,\qquad\sum_{i=1}^{d}p_{i}=1.$

Since $CC^{\dagger}$ and $C^{\dagger}C$ have the same multiset of eigenvalues, the same diagonal matrix $D$ appears in both formulas.

Now define

$M:=UCV^{T}.$

Then

$MM^{\dagger}=(UCV^{T})(UCV^{T})^{\dagger}=UCV^{T}\overline{V}\,C^{\dagger}U^{\dagger}=UCC^{\dagger}U^{\dagger}=D,$

---

and similarly

$M^{\dagger}M=(UCV^{T})^{\dagger}(UCV^{T})=\overline{V}\,C^{\dagger}U^{\dagger}UCV^{T}=\overline{V}\,C^{\dagger}C\,V^{T}=D.$

Hence

$MM^{\dagger}=M^{\dagger}M=D,$

so $M$ is normal. Moreover,

$MD=M(M^{\dagger}M)=(MM^{\dagger})M=DM,$

thus $M$ commutes with $D$.

Since $M$ and $D$ are commuting normal matrices, they can be simultaneously unitarily diagonalized. Therefore there exists a unitary $W$ such that

$WMW^{\dagger}=\Lambda,\qquad WDW^{\dagger}=\Delta,$

with both $\Lambda$ and $\Delta$ diagonal. Since $D$ is already diagonal, after possibly reordering the basis vectors we may assume

$WDW^{\dagger}=D.$

Set

$\widetilde{U}:=WU,\qquad\widetilde{V}:=\overline{W}\,V.$

Then

$\widetilde{U}\,C\,\widetilde{V}^{T}=WU\,C\,(\overline{W}\,V)^{T}=WU\,C\,V^{T}W^{\dagger}=WMW^{\dagger}=\Lambda,$

so $\widetilde{U}C\widetilde{V}^{T}$ is diagonal. Write

$\Lambda=\text{diag}(\lambda_{1},\ldots,\lambda_{d}).$

Since

$\Lambda\Lambda^{\dagger}=WMM^{\dagger}W^{\dagger}=WDW^{\dagger}=D,$

we obtain

$|\lambda_{i}|^{2}=p_{i}\qquad\text{for all }i.$

Therefore

$\Lambda=\text{diag}\big{(}\sqrt{p_{1}}e^{i\theta_{1}},\ldots,\sqrt{p_{d}}e^{i\theta_{d}}\big{)}.$

Absorbing the phases into the basis vectors of one subsystem, we may assume

$\Lambda=\text{diag}(\sqrt{p_{1}},\ldots,\sqrt{p_{d}}).$

Thus

$(\widetilde{U}\otimes\widetilde{V})|\psi\rangle=\sum_{i=1}^{d}\sqrt{p_{i}}\,|i\rangle\otimes|i\rangle.$

Equivalently,

$|\psi\rangle=\sum_{i=1}^{d}\sqrt{p_{i}}\,|u_{i}\rangle\otimes|v_{i}\rangle,$

---

$\left|u_{i}\right\rangle=\widetilde{U}^{\dagger}|i\rangle,\qquad\left|v_{i}\right\rangle=\widetilde{V}^{\dagger}|i\rangle.$

This is the Schmidt decomposition. Hence, there exist unitary operators $\tilde{U},\tilde{V}$ such that:

1. $\tilde{U}\otimes\tilde{V}|\Psi\rangle=\sum_{i=0}^{d-1}\sqrt{p_{i}}|i\rangle\otimes|i\rangle$
2. $\rho_{1}=\sum p_{i}|i\rangle\langle i|,\quad\rho_{2}=\sum p_{i}|i\rangle\langle i|,\quad\text{with }\sum p_{i}=1,p_{i}\geq 0$

### 4.2 Entanglement

A fundamental feature of quantum entanglement is the distinction between global purity and local mixedness. Even if a total bipartite state $|\Psi\rangle\in\mathcal{H}_{1}\otimes\mathcal{H}_{2}$ is completely known and pure, the reduced states of its subsystems, $\rho_{1}=\mathrm{tr}_{2}(|\Psi\rangle\langle\Psi|)$ and $\rho_{2}=\mathrm{tr}_{1}(|\Psi\rangle\langle\Psi|)$, can be mixed. A pure state $|\Psi\rangle$ is considered separable (or unentangled) if and only if it can be factored into a simple tensor product $|\varphi_{1}\rangle\otimes|\varphi_{2}\rangle$. In terms of the Schmidt decomposition, this occurs precisely when there is exactly one non-zero Schmidt coefficient (i.e., $p_{1}=1$, and all others are $0$). For such separable states, the reduced density matrices $\rho_{1}$ and $\rho_{2}$ remain pure.

Conversely, a state $|\Psi\rangle$ is entangled if it cannot be written as a simple tensor, which corresponds to having strictly more than one non-zero Schmidt coefficient. Consequently, the reduced states $\rho_{1}$ and $\rho_{2}$ become mixed. The degree of this local mixedness is exactly what quantifies the entanglement. For pure bipartite states, this is measured by the entropy of entanglement, defined as the von Neumann entropy of either reduced subsystem. Because the non-zero eigenvalues of $\rho_{1}$ and $\rho_{2}$ are identically the Schmidt coefficients $p_{i}$, their entropies are equal:

$S_{E}(|\Psi\rangle)=S(\rho_{1})=S(\rho_{2})=-\,\mathrm{tr}(\rho_{1}\log\rho_{1})=-\sum_{i=1}^{d}p_{i}\log(p_{i})$

As expected, for a separable state $|\varphi_{1}\rangle\otimes|\varphi_{2}\rangle$, this entropy evaluates to zero.

Importantly, entanglement is a non-local property and cannot be altered by local operations. The entropy of entanglement is invariant under local unitary transformations $U\otimes V$:

$S_{E}(U\otimes V|\Psi\rangle)=S(U\rho_{1}U^{\dagger})=S(\rho_{1})=S_{E}(|\Psi\rangle)$

The entanglement entropy reaches its theoretical maximum of $\log(d)$ for a maximally entangled state. In this case, the reduced density matrices are maximally mixed ($\rho_{1}=\rho_{2}=\frac{1}{d}I$), meaning all $d$ Schmidt coefficients are uniformly distributed ($p_{i}=1/d$). The standard representation of such a state is:

$|\Psi_{\mathrm{max}}\rangle=\frac{1}{\sqrt{d}}\sum_{i=0}^{d-1}|i,i\rangle$

---

4.3 Creating a Mixed State

A way of creating a mixed state: Alice gets many copies of system $\mathcal{H}$ prepared in a known state $\ket{\psi}$. For each copy, she measures an observable $F:\mathcal{H}\to\mathcal{H}$ and gives this copy to Bob. Bob knows that Alice measured $F$ and that the starting state was $\ket{\psi}$. However, he doesn’t know the result of every single measurement of $F$ performed by Alice.

Let the spectral decomposition of the observable $F$ be:

$F=\sum_{\lambda\in\sigma(F)}\lambda P_{\lambda}$

where $\sigma(F)$ is the spectrum of $F$, and $P_{\lambda}$ are the orthogonal projectors.

When Alice measures a copy, if the outcome is $\lambda$, the state collapses to:

$\frac{P_{\lambda}\ket{\psi}}{\|P_{\lambda}\psi\|}$

Because Bob does not know the specific outcome, he regards the states he receives as elements of a statistical ensemble:

$\left\{\frac{P_{\lambda}\ket{\psi}}{\|P_{\lambda}\psi\|},\quad p_{\ket{\psi}}(\lambda)=\bra{\psi}P_{\lambda}\ket{\psi}\right\}_{\lambda\in\sigma(F)}$

where $p_{\ket{\psi}}(\lambda)$ is the probability of obtaining outcome $\lambda$.

Thus, Bob describes his system using the density operator $\rho$:

$\rho$ $=\sum_{\lambda}p_{\ket{\psi}}(\lambda)\left(\frac{P_{\lambda}\ket{\psi}\bra{\psi}P_{\lambda}^{\dagger}}{\|P_{\lambda}\psi\|^{2}}\right)$  
$=\sum_{\lambda\in\sigma(F)}\bra{\psi}P_{\lambda}\ket{\psi}\frac{P_{\lambda}\ket{\psi}\bra{\psi}P_{\lambda}}{\bra{\psi}P_{\lambda}\ket{\psi}}$  
$=\sum_{\lambda\in\sigma(F)}P_{\lambda}\ket{\psi}\bra{\psi}P_{\lambda}$

### 4.4 Cyclicity of the Partial Trace

Claim: Let $\mathcal{H}=\mathcal{H}_{1}\otimes\mathcal{H}_{2}$. For $A\otimes B:\mathcal{H}\to\mathcal{H}$, the partial trace over $\mathcal{H}_{1}$ is:

$\mathrm{tr}_{1}(A\otimes B)=\mathrm{tr}(A)B$

###### Proof.

Let $\{\ket{i}\}$ be an orthonormal basis for the Hilbert space $\mathcal{H}_{1}$. Let $I_{2}$ be the identity operator acting on the second Hilbert space $\mathcal{H}_{2}$. The partial trace of a joint operator $O$ acting on $\mathcal{H}_{1}\otimes\mathcal{H}_{2}$ over the first subsystem $\mathcal{H}_{1}$ is defined by tracing out the basis states of $\mathcal{H}_{1}$:

$\mathrm{tr}_{1}(O)=\sum_{i}(\bra{i}\otimes I_{2})O(\ket{i}\otimes I_{2})$

---

Let $O=A\otimes B$. Substituting this into the definition yields:

$\mathrm{tr}_{1}(A\otimes B)=\sum_{i}(\langle i|\otimes I_{2})(A\otimes B)(|i\rangle\otimes I_{2})$

Using the mixed-product property of tensor products, $(V\otimes W)(X\otimes Y)=(VX)\otimes(WY)$, we can evaluate the action of the bras and kets:

$\mathrm{tr}_{1}(A\otimes B)$ $=\sum_{i}(\langle i|\,A\,|i\rangle)\otimes(I_{2}BI_{2})$  
$=\sum_{i}(\langle i|\,A\,|i\rangle)\otimes B=\mathrm{tr}(A)B$

$\mathcal{H}_{1}$:

$\sum_{i}\langle i|\,A\,|i\rangle=\mathrm{tr}(A)$

Substituting this back into the equation gives the final result:

$\mathrm{tr}_{1}(A\otimes B)=\mathrm{tr}(A)B$

∎

###### Fact.

Partial trace is cyclic in the factors that are traced out.

###### Proof.

Let $\mathcal{H}=\mathcal{H}_{1}\otimes\mathcal{H}_{2}$. Consider the product of three simple tensor operators, $O_{1}=A\otimes D$, $O_{2}=B\otimes E$, and $O_{3}=C\otimes F$.

Taking the partial trace over $\mathcal{H}_{1}$ yields:

$\mathrm{tr}_{1}\left((A\otimes D)(B\otimes E)(C\otimes F)\right)$ $=\mathrm{tr}_{1}(ABC\otimes DEF)$  
$=\mathrm{tr}(ABC)DEF$

Because the standard trace is cyclic, we know $\mathrm{tr}(ABC)=\mathrm{tr}(CAB)$. Thus, if we cyclically permute only the factors acting on the traced-out subsystem $\mathcal{H}_{1}$, the result remains invariant:

$\mathrm{tr}_{1}\left((C\otimes D)(A\otimes E)(B\otimes F)\right)$ $=\mathrm{tr}_{1}(CAB\otimes DEF)$  
$=\mathrm{tr}(CAB)DEF$  
$=\mathrm{tr}(ABC)DEF$

Since any general operators on $\mathcal{H}$ can be written as linear combinations of simple tensors, and the partial trace is a linear map, this cyclic property extends to all operators by linearity. ∎

### 4.5 Measurements on Subsystems

Let $\mathcal{H}=\mathcal{H}_{A}\otimes\mathcal{H}_{B}$. Suppose we have a total state $\rho$. The reduced states are $\rho_{A}=\mathrm{tr}_{B}(\rho)$ and $\rho_{B}=\mathrm{tr}_{A}(\rho)$.

---

Let $U:\mathcal{H}_{A}\to\mathcal{H}_{A}$ be a unitary. If we apply $U\otimes I:\mathcal{H}_{A}\otimes\mathcal{H}_{B}\to\mathcal{H}_{A}\otimes\mathcal{H}_{B}$, we have previously seen that:

$\rho_{A}\big{(}(U\otimes I)\rho(U^{\dagger}\otimes I)\big{)}$ $=U\rho_{A}U^{\dagger}$  
$\rho_{B}\big{(}(U\otimes I)\rho(U^{\dagger}\otimes I)\big{)}$ $=\rho_{B}$

Question: What happens with $\rho_{B}$ if we measure an observable $M_{A}$ on $\mathcal{H}_{A}$?

Let the measurement on $A$ be $M_{A}=\sum_{\lambda\in\sigma(M)}\lambda P_{\lambda}$. Extended to the joint space, this is:

$M_{A}\otimes I=\sum_{\lambda\in\sigma(M)}\lambda(P_{\lambda}\otimes I)\quad\text{where}\quad\sum_{\lambda\in\sigma(M)}P_{\lambda}\otimes I=I\otimes I$

If the result of the measurement is $\lambda$, then the state of the joint system collapses to:

$\rho_{\lambda}=\frac{(P_{\lambda}\otimes I)\rho(P_{\lambda}\otimes I)}{\operatorname{tr}(\rho(P_{\lambda}\otimes I))}$

This outcome occurs with probability $p(\lambda)=\operatorname{tr}(\rho(P_{\lambda}\otimes I))$. That means with probability $p(\lambda)$, the state of subsystem $\mathcal{H}_{B}$ after measurement is $\rho_{B}(\rho_{\lambda})=\operatorname{tr}_{A}(\rho_{\lambda})$. Hence, if the measurement is performed but the outcome is unknown, the state of subsystem $B$ can be described by the expected reduced state:

$\sum_{\lambda\in\sigma(M_{A})}\operatorname{tr}(\rho(P_{\lambda}\otimes I))\operatorname{tr}_{A}(\rho_{\lambda})$ $=\sum_{\lambda\in\sigma(M_{A})}\operatorname{tr}_{A}\big{(}(P_{\lambda}\otimes I)\rho(P_{\lambda}\otimes I)\big{)}$  
$\stackrel{{\scriptstyle\text{cyclic in A}}}{{=}}\sum_{\lambda\in\sigma(M_{A})}\operatorname{tr}_{A}\big{(}(P_{\lambda}\otimes I)(P_{\lambda}\otimes I)\rho\big{)}$  
$\stackrel{{\scriptstyle P_{\lambda}^{2}=P_{\lambda}}}{{=}}\sum_{\lambda\in\sigma(M_{A})}\operatorname{tr}_{A}\big{(}(P_{\lambda}\otimes I)\rho\big{)}$  
$=\operatorname{tr}_{A}\left(\Big{(}\sum_{\lambda\in\sigma(M_{A})}P_{\lambda}\otimes I\Big{)}\rho\right)$  
$=\operatorname{tr}_{A}\big{(}(I\otimes I)\rho\big{)}$  
$=\operatorname{tr}_{A}(\rho)=\rho_{B}$

Justification for the cyclic step:

Any joint state $\rho$ on $\mathcal{H}_{A}\otimes\mathcal{H}_{B}$ can be expanded as a linear combination of simple tensors: $\rho=\sum_{i,j}c_{ij}(A_{i}\otimes B_{j})$.

Substituting this expansion into our expression, we can use the linearity of

---

matrix multiplication, the tensor product, and the partial trace:

$$
\begin{array}{l}
\operatorname{tr}_{A} \left((P_{\lambda} \otimes I) \rho(P_{\lambda} \otimes I)\right) = \operatorname{tr}_{A} \left((P_{\lambda} \otimes I) \left(\sum_{i,j} c_{ij}(A_{i} \otimes B_{j})\right) (P_{\lambda} \otimes I)\right) \\
= \operatorname{tr}_{A} \left(\sum_{i,j} c_{ij}(P_{\lambda} A_{i} P_{\lambda} \otimes B_{j})\right) \\
= \sum_{i,j} c_{ij} \operatorname{tr}_{A} (P_{\lambda} A_{i} P_{\lambda} \otimes B_{j}) \\
= \sum_{i,j} c_{ij} \operatorname{tr}(P_{\lambda} A_{i} P_{\lambda}) B_{j} \\
= \sum_{i,j} c_{ij} \operatorname{tr}(P_{\lambda} P_{\lambda} A_{i}) B_{j} = \sum_{i,j} c_{ij} \operatorname{tr}(P_{\lambda}^{2} A_{i}) B_{j} \\
= \sum_{i,j} c_{ij} \operatorname{tr}_{A} (P_{\lambda}^{2} A_{i} \otimes B_{j}) \\
= \operatorname{tr}_{A} \left(\sum_{i,j} c_{ij} (P_{\lambda}^{2} A_{i} \otimes B_{j})\right) \\
= \operatorname{tr}_{A} \left((P_{\lambda}^{2} \otimes I) \left(\sum_{i,j} c_{ij} (A_{i} \otimes B_{j})\right)\right) \\
= \operatorname{tr}_{A} \left((P_{\lambda}^{2} \otimes I) \rho\right)
\end{array}
$$

Because $P_{\lambda}$ is an orthogonal projector, $P_{\lambda}^{2} = P_{\lambda}$. Therefore, $\operatorname{tr}_{A} \left((P_{\lambda} \otimes I) \rho(P_{\lambda} \otimes I)\right) = \operatorname{tr}_{A} \left((P_{\lambda} \otimes I) \rho\right)$.

**Conclusion:**  The reduced state is the *same as before the measurement!*  Knowing that some measurements are performed on system $A$, but not getting information on their results, does not change $\rho_{B}$. (Note: This is a manifestation of the no-communication theorem).

27

---

Matrix Lie groups and Lie algebras

We will use notation $\mathbb{K}=\mathbb{R},\mathbb{C}$. $M_{n}(\mathbb{K})$ - $n\times n$ matrices with entries from $\mathbb{K}$ and $GL(n,\mathbb{K})=\{A\in M_{n}(\mathbb{K})\mid\det(A)\neq 0\}$

###### Definition.

A matrix Lie group $G$ is a subset of $GL(n,\mathbb{C})$ s.t. that

1. $A,B\in G\implies A\cdot B\in G$
2. $A\in G\implies A^{-1}\in G$
3. $I\in G$
4. $G$ is a closed subgroup of $GL(n,\mathbb{K})$

Recall that matrix multiplication, transposition, and dagger are continuous operations

###### Example.

To show that these subsets are matrix Lie groups, we verify that they are closed subsets of $GL(n,\mathbb{K})$ by proving that the limit of any convergent sequence within the subset also belongs to that subset.

1. Special Linear Group: $SL(n,\mathbb{K})=\{A\in GL(n,\mathbb{K})\mid\det(A)=1\}$  
   Let $(A_{m})_{m=1}^{\infty}$ be a sequence of matrices in $SL(n,\mathbb{K})$ that converges to some matrix $A$. Because the determinant is a continuous function, we can pass the limit inside:

$\det(A)=\det\Big{(}\lim_{m\to\infty}A_{m}\Big{)}=\lim_{m\to\infty}\det(A_{m})=\lim_{m\to\infty}(1)=1$

Since $\det(A)=1$, we know $A\in SL(n,\mathbb{K})$.  
2. Unitary Group: $U(n)=\{U\in GL(n,\mathbb{C})\mid UU^{\dagger}=I=U^{\dagger}U\}$  
Let $(U_{m})_{m=1}^{\infty}$ be a sequence such that $U_{m}\in U(n)$ for all $m$, and let $\lim_{m\to\infty}U_{m}=V$. To show that $V\in U(n)$, we must demonstrate that $VV^{\dagger}=I$. Because matrix multiplication and the conjugate transpose (^{†}) are continuous operations, we can distribute and pull the limit inside:

$I$ $=\lim_{m\to\infty}I$  
$=\lim_{m\to\infty}(U_{m}U_{m}^{\dagger})$  
$=\Big{(}\lim_{m\to\infty}U_{m}\Big{)}\cdot\Big{(}\lim_{m\to\infty}U_{m}^{\dagger}\Big{)}$  
$=V\cdot\Big{(}\lim_{m\to\infty}U_{m}\Big{)}^{\dagger}$  
$=VV^{\dagger}$

Therefore, $V\in U(n)$.  
3. Special Unitary Group: $SU(n)=\{U\in U(n)\mid\det(U)=1\}$  
This is closed because it is the intersection of two closed sets: $U(n)$ and $SL(n,\mathbb{C})$.

###### 

---

4. **Orthogonal Group**: $O(n) = \{O \in GL(n, \mathbb{R}) \mid OO^T = I = O^T O\}$

The proof of closure is identical to the unitary case, relying on the fact that the matrix transpose operation $(^T)$ is continuous.

5. **Special Orthogonal Group**: $SO(n) = \{O \in O(n) \mid \det(O) = 1\}$

This is closed because it is the intersection of two closed sets: $O(n)$ and $SL(n, \mathbb{R})$.

**Definition.**  Let $G, H$ be matrix Lie groups. A map $\Phi : G \to H$ is called Lie group homomorphism iff

1. $\Phi(g_1g_2) = \Phi(g_1) \cdot \Phi(g_2) \quad \forall g_1, g_2 \in G$
2. $\Phi(I) = I$
3. $\Phi$ is continuous

If $\Phi$ is 1-1 and $\Phi^{-1}$ is continuous we call it Lie group isomorphism.

**Example** $\Phi : \mathbb{R} \to SO(2)$, $\Phi(\theta) = \begin{pmatrix} \cos \theta & -\sin \theta \\ \sin \theta & \cos \theta \end{pmatrix}$ $\leftarrow$ Lie group homomorphism

**Theorem (Lie Product formula).**  Let $X, Y \in M_n(\mathbb{C})$. Then $e^{X + Y} = \lim_{m \to \infty} \left[ e^{\frac{X}{m}} e^{\frac{Y}{m}} \right]^m$.

**Proof.**  $e^{A} = \lim_{n\to \infty}\left(I + \frac{A_{n}}{n}\right)^{n}$, where $A_{n}$ is such that $\lim_{n\to \infty}A_n = A$.

Define $X_{n} = n(e^{\frac{X}{n}} - I)$, $Y_{n} = n(e^{\frac{Y}{n}} - I)$, $\lim_{n\to \infty}X_n = X$, $\lim_{n\to \infty}Y_n = Y$.

$$
X _ {n} Y _ {n} = n ^ {2} \left(e ^ {\frac {X}{n}} e ^ {\frac {Y}{n}} - e ^ {\frac {X}{n}} - e ^ {\frac {Y}{n}} + I\right) \Rightarrow e ^ {\frac {X}{n}} \cdot e ^ {\frac {Y}{n}} = \frac {X _ {n} Y _ {n}}{n ^ {2}} + e ^ {\frac {X}{n}} + e ^ {\frac {Y}{n}} - I
$$

$$
\begin{array}{l}
\left(e ^ {\frac {X}{n}} \cdot e ^ {\frac {Y}{n}}\right) ^ {n} = \left(I + \frac {X _ {n} + Y _ {n}}{n} + \frac {X _ {n} \cdot Y _ {n}}{n ^ {2}}\right) ^ {n}, \quad \text{let } Z _ {n} = X _ {n} + Y _ {n} + \frac {X _ {n} Y _ {n}}{n}, \quad \lim  _ {n \rightarrow \infty} Z _ {n} = X + Y \\
\lim  _ {n \rightarrow \infty} \left(e ^ {\frac {X}{n}} e ^ {\frac {Y}{n}}\right) ^ {n} = \lim  _ {n \rightarrow \infty} \left(I + \frac {Z _ {n}}{n}\right) ^ {n} = e ^ {X + Y} \\
\end{array}
$$

□

**Definition.**  A finite dimensional real or complex Lie algebra is a finite dimensional vector space $\mathfrak{g}$ over $\mathbb{R}$ or $\mathbb{C}$ together with the map that we call a **Lie bracket** $[\cdot, \cdot] : \mathfrak{g} \times \mathfrak{g} \to \mathfrak{g}$

1. $[\cdot, \cdot]$ - bilinear
2. $[X,Y] = -[Y,X] \quad \forall X,Y \in \mathfrak{g}$
3. The Jacobi identity: $[X, [Y, Z]] + [Y, [Z, X]] + [Z, [X, Y]] = 0$

**Remark** $[X,Y] = 0$ we say $X,Y$ commute

**Example 1** $\mathfrak{g} = \mathbb{R}^3$, $[\cdot, \cdot] : \mathbb{R}^3 \times \mathbb{R}^3 \to \mathbb{R}^3$ $[x, y] = x \times y$

**Example 2** Let $\mathbb{K} = \mathbb{R}, \mathbb{C}$. $\mathfrak{g} = M_n(\mathbb{K})$ with $[\cdot, \cdot] : \mathfrak{g} \times \mathfrak{g} \to \mathfrak{g}$ given by matrix commutator $[A, B] = AB - BA$ is real/complex Lie algebra.

29

---

Definition. Let $(\mathfrak{g},[\cdot ,\cdot ]_{\mathfrak{g}})$ and $(\mathfrak{h},[\cdot ,\cdot ]_{\mathfrak{h}})$ be two real (complex) Lie algebras. A real/complex linear map $\phi :\mathfrak{g}\to \mathfrak{h}$ that satisfies $\phi ([X,Y]_{\mathfrak{g}}) = [\phi (X),\phi (Y)]_{\mathfrak{h}}$ is called Lie algebra homomorphism.

Definition. Let $G$ be a matrix Lie group. The Lie algebra of $G$, denoted by $\mathfrak{g} = \operatorname{Lie}(G)$, is the set of all matrices $X$ such that $e^{tX}$ is in $G \forall t \in \mathbb{R}$.

Thus $X \in \mathfrak{g}$ iff 1-parameter group generated by $X$, that is, $\{e^{tX} \mid t \in \mathbb{R}\}$ belongs to $G$.

Fact. Let $G$ be a matrix Lie group and $\mathfrak{g} = \operatorname{Lie}(G)$. Then

$1^{\circ}$ $gXg^{-1}\in \mathfrak{g},\quad \forall g\in G,\forall X\in \mathfrak{g}$

$2^{\circ}$ $\alpha X\in \mathfrak{g},\quad \forall \alpha \in \mathbb{R},\forall X\in \mathfrak{g}$

$3^{\circ}$ $X + Y\in \mathfrak{g},\quad \forall X\in \mathfrak{g},\forall Y\in \mathfrak{g}$

$4^{\circ}$ $XY - YX\in \mathfrak{g},\quad \forall X,Y\in \mathfrak{g}$

Proof. $1^{\circ}$ Let $X \in \mathfrak{g}$, then $e^{tgXg^{-1}} = g \underbrace{e^{tX}}_{\in G \forall t} g^{-1} \in G \quad \forall t \Rightarrow gXg^{-1} \in \mathfrak{g}$

$2^{\circ}$ assume $X \in \mathfrak{g}$, $e^{t\alpha X} \in G \forall t \Rightarrow \alpha X \in \mathfrak{g} \alpha \in \mathbb{R}$

$3^{\circ}$ $e^{t(X + Y)} = \lim_{m\to \infty}(\underbrace{e^{\frac{t}{\alpha} X}}_{\text{belong to } G\text{ belong to } G},\underbrace{e^{\frac{t}{\alpha} Y}}_{\text{belong to } G})^m,$ Thus $e^{t(X + Y)}$ is an invertible matrix given by the limit of sequence of elements from $G$ and therefore is in $G$. (as $G$ is closed)

$4^{\circ}$ $(e^{tX}Ye^{-tX})$ - belongs to $\mathfrak{g}$ for every $t$. By $2^{\circ}, 3^{\circ} \mathfrak{g}$ is a real vector subspace of $M_{n}(\mathbb{C})$.

$$
\lim _ {t \to 0} \frac {e ^ {t X} Y e ^ {- t X} - Y}{t}
$$

if exist belongs to $\mathfrak{g}$. But

$$
\lim _ {t \to 0} \frac {e ^ {t X} Y e ^ {- t X} - Y}{t} = \left. \frac {d}{d t} \right| _ {t = 0} e ^ {t X} Y e ^ {- t X} = X Y \cdot e ^ {0} - e ^ {0} Y X = X Y - Y X
$$

Example. $\bullet \operatorname{Lie}(GL(n,\mathbb{K})) = M_n(\mathbb{K}) =: \mathfrak{gl}(n,\mathbb{K})$

$\bullet \operatorname {Lie}(SL(n,\mathbb{K})) = \mathfrak{sl}(n,\mathbb{K}) = \{X\in M_n(\mathbb{K})\mid \operatorname {tr}(X) = 0\}$  
$\bullet \operatorname {Lie}(U(n)) = \mathfrak{u}(n) = \{X\in M_n(\mathbb{C})\mid X^\dagger = -X\}$  
$\bullet \operatorname {Lie}(SU(n)) = \mathfrak{su}(n) = \{X\in M_n(\mathbb{C})\mid X^\dagger = -X\text{ and }\operatorname {tr}(X) = 0\}$  
$\bullet \operatorname {Lie}(O(n)) = \mathfrak{o}(n) = \{X\in M_n(\mathbb{R})\mid X^T = -X\}$  
$\bullet \operatorname {Lie}(SO(n)) = \mathfrak{so}(n) = \{X\in M_n(\mathbb{R})\mid X^T = -X\}$

---

###### Definition.

A 1-parameter subgroup of $GL(n,\mathbb{C})$ is a map

$\mathbb{R}$ $\to GL(n,\mathbb{C})$  
$t$ $\mapsto g(t)$

That satisfies: 1) $g(0)=I$, 2) $g(t+s)=g(t)\cdot g(s)$ 3) $g(t)$ is continuous

###### Theorem.

If $g(t)$ is 1-parameter subgroup of a matrix Lie group $G\subset GL(n,\mathbb{C})$ then there is unique $X\in M_{n}(\mathbb{C})$ s.t. $U(t)=e^{tX}\quad\forall t\in\mathbb{R}$. By our definition of the Lie algebra of $G$, this also means that $X\in\mathfrak{g}$.

###### Theorem.

Let $G$ and $H$ be matrix Lie groups with corresponding Lie algebras $\mathfrak{g}=\mathrm{Lie}(G)$ and $\mathfrak{h}=\mathrm{Lie}(H)$. Let $\Phi:G\to H$ be a Lie group homomorphism. Then there is a unique real-linear map $\varphi:\mathfrak{g}\to\mathfrak{h}$ such that:

$\Phi(e^{X})=e^{\varphi(X)}\quad\text{for all }X\in\mathfrak{g}$

This map satisfies the following additional properties:

1. $\varphi(X)=\frac{d}{dt}\Big{|}_{t=0}\Phi(e^{tX})\quad\text{for all }X\in\mathfrak{g}$
2. $\varphi(gXg^{-1})=\Phi(g)\varphi(X)\Phi(g)^{-1}\quad\text{for all }g\in G,X\in\mathfrak{g}$
3. $\varphi([X,Y])=[\varphi(X),\varphi(Y)]\quad\text{for all }X,Y\in\mathfrak{g}$

###### Proof.

Step 1: Existence and Definition (Property 1)  
For any $X\in\mathfrak{g}$, the curve $t\mapsto\Phi(e^{tX})$ is a continuous one-parameter subgroup of $H$ because $\Phi$ is a continuous homomorphism. A standard result for matrix Lie groups states that every continuous one-parameter subgroup has a unique generator in the corresponding Lie algebra. Thus, there exists a unique element $Z\in\mathfrak{h}$ such that:

$\Phi(e^{tX})=e^{tZ}\quad\text{for all }t\in\mathbb{R}$

We define $\varphi(X)=Z$. Evaluating at $t=1$ gives the primary condition $\Phi(e^{X})=e^{\varphi(X)}$. Furthermore, taking the derivative at $t=0$ immediately yields Property 1:

$\frac{d}{dt}\Big{|}_{t=0}\Phi(e^{tX})=\frac{d}{dt}\Big{|}_{t=0}e^{tZ}=Z=\varphi(X)$

Step 2: Linearity of $\varphi$  
First, we prove preservation of scalar multiplication. For any $\alpha\in\mathbb{R}$:

$e^{t\varphi(\alpha X)}=\Phi(e^{t(\alpha X)})=\Phi(e^{(t\alpha)X})=e^{(t\alpha)\varphi(X)}=e^{t(\alpha\varphi(X))}$

Differentiating both sides at $t=0$ gives $\varphi(\alpha X)=\alpha\varphi(X)$.

Next, we prove additivity using the Lie product formula. For any $X,Y\in\mathfrak{g}$:

$e^{t\varphi(X+Y)}=\Phi(e^{t(X+Y)})=\Phi\left(\lim_{n\to\infty}\left(e^{\frac{tX}{n}}e^{\frac{tY}{n}}\right)^{n}\right)$

---

Because $\Phi$ is a continuous homomorphism, we can pull the limit outside:

$e^{t\varphi(X+Y)}=\lim_{n\to\infty}\left(\Phi\left(e^{\frac{tX}{n}}\right)\Phi\left(e^{\frac{tY}{n}}\right)\right)^{n}=\lim_{n\to\infty}\left(e^{\frac{t}{n}\varphi(X)}e^{\frac{t}{n}\varphi(Y)}\right)^{n}$

Applying the Lie product formula in $\mathfrak{h}$ yields:

$e^{t\varphi(X+Y)}=e^{t(\varphi(X)+\varphi(Y))}$

Differentiating both sides at $t=0$ shows $\varphi(X+Y)=\varphi(X)+\varphi(Y)$. Thus, $\varphi$ is $\mathbb{R}$-linear.

Step 3: Uniqueness

Suppose $\phi^{\prime}:\mathfrak{g}\to\mathfrak{h}$ is another real-linear map satisfying $\Phi(e^{X})=e^{\phi^{\prime}(X)}$ for all $X\in\mathfrak{g}$. Then:

$e^{t\varphi(X)}=\Phi(e^{tX})=e^{\phi^{\prime}(tX)}=e^{t\phi^{\prime}(X)}$

Differentiating at $t=0$ guarantees that $\varphi(X)=\phi^{\prime}(X)$.

Step 4: Adjoint Compatibility (Property 2)

Let $g\in G$ and $X\in\mathfrak{g}$. We evaluate $\Phi(e^{tgXg^{-1}})$ in two different ways. On one hand, applying the definition of $\varphi$ directly:

$\Phi(e^{tgXg^{-1}})=e^{t\varphi(gXg^{-1})}$

On the other hand, applying the standard identity $e^{gAg^{-1}}=ge^{A}g^{-1}$ and the homomorphism $\Phi$:

$\Phi(e^{tgXg^{-1}})=\Phi(ge^{tX}g^{-1})=\Phi(g)\Phi(e^{tX})\Phi(g)^{-1}=\Phi(g)e^{t\varphi(X)}\Phi(g)^{-1}$

Applying the exponential identity again in $H$ gives:

$\Phi(g)e^{t\varphi(X)}\Phi(g)^{-1}=e^{t\Phi(g)\varphi(X)\Phi(g)^{-1}}$

Equating the exponents’ derivatives at $t=0$ yields $\varphi(gXg^{-1})=\Phi(g)\varphi(X)\Phi(g)^{-1}$.

Step 5: Preservation of the Lie Bracket (Property 3)

Recall the standard relation for matrix Lie algebras: $[X,Y]=\frac{d}{dt}\Big{|}_{t=0}e^{tX}Ye^{-tX}$. Because $\varphi$ is a linear map between finite-dimensional spaces, it is continuous, allowing us to interchange it with the derivative:

$\varphi([X,Y])$ $=\varphi\left(\frac{d}{dt}\Big{|}_{t=0}e^{tX}Ye^{-tX}\right)$  
$=\frac{d}{dt}\Big{|}_{t=0}\varphi(e^{tX}Ye^{-tX})$

Applying Property 2 (substituting $g=e^{tX}$) gives:

$\varphi([X,Y])=\frac{d}{dt}\Big{|}_{t=0}\left(\Phi(e^{tX})\varphi(Y)\Phi(e^{-tX})\right)$

Since $\Phi(e^{tX})=e^{t\varphi(X)}$, this becomes:

$\varphi([X,Y])=\frac{d}{dt}\Big{|}_{t=0}\left(e^{t\varphi(X)}\varphi(Y)e^{-t\varphi(X)}\right)=[\varphi(X),\varphi(Y)]$

∎

## 

---

Remark Every Lie group homomorphism induces Lie algebra homomorphism.

###### Definition (The Adjoint Map).

Let $G$ be a matrix Lie group with Lie algebra $\mathfrak{g}$. For every element $g\in G$, we define the adjoint map $\mathrm{Ad}_{g}:\mathfrak{g}\to\mathfrak{g}$ by:

$\mathrm{Ad}_{g}(X)=gXg^{-1}$

###### Fact (Linearity and Invertibility).

For every $g\in G$, the map $\mathrm{Ad}_{g}:\mathfrak{g}\to\mathfrak{g}$ is a linear isomorphism (i.e., it is both linear and invertible).

###### Proof.

Let $X,Y\in\mathfrak{g}$ and let $\alpha\in\mathbb{R}$.

1. Additivity: $\mathrm{Ad}_{g}(X+Y)=g(X+Y)g^{-1}=gXg^{-1}+gYg^{-1}=\mathrm{Ad}_{g}(X)+\mathrm{Ad}_{g}(Y)$
2. Homogeneity: $\mathrm{Ad}_{g}(\alpha X)=g(\alpha X)g^{-1}=\alpha(gXg^{-1})=\alpha\,\mathrm{Ad}_{g}(X)$
3. Invertibility: To show it is invertible, we can explicitly find its inverse. Note that applying $\mathrm{Ad}_{g^{-1}}$ undoes the operation:

$\mathrm{Ad}_{g^{-1}}(\mathrm{Ad}_{g}(X))=g^{-1}(gXg^{-1})g=(g^{-1}g)X(g^{-1}g)=X$

Therefore, the inverse map is given by $(\mathrm{Ad}_{g})^{-1}=\mathrm{Ad}_{g^{-1}}$.

∎

## 5 Adjoint homomorphism

Remark on Dimensions: The Lie algebra $\mathfrak{g}=\mathrm{Lie}(G)$ is a real vector space. If $\dim(\mathfrak{g})=k$, then the group of all invertible linear maps on $\mathfrak{g}$, denoted $GL(\mathfrak{g})$, is isomorphic to $GL(k,\mathbb{R})$. Because $\mathrm{Ad}_{g}$ is an invertible linear transformation on $\mathfrak{g}$, it follows that $\mathrm{Ad}_{g}\in GL(\mathfrak{g})$. Consequently, $GL(\mathfrak{g})$ itself is a matrix Lie group.

###### Fact (The Adjoint Representation).

Let $GL(\mathfrak{g})$ be the group of all invertible linear maps on $\mathfrak{g}$. Then the map $\mathrm{Ad}:G\to GL(\mathfrak{g})$ defined by:

$g\mapsto\mathrm{Ad}_{g}$

is a Lie group homomorphism. Furthermore, for every $g\in G$, the map $\mathrm{Ad}_{g}$ preserves the Lie bracket:

$\mathrm{Ad}_{g}([X,Y])=[\mathrm{Ad}_{g}(X),\mathrm{Ad}_{g}(Y)]$

###### Proof.

To prove that $\mathrm{Ad}$ is a Lie group homomorphism, we must show that it maps the identity to the identity, preserves the group operation, and is continuous.

1. Identity Preservation: For the identity matrix $I\in G$,

$\mathrm{Ad}_{I}(X)=IXI^{-1}=X$

Therefore, $\mathrm{Ad}_{I}=\mathrm{id}_{\mathfrak{g}}$.  
2.

---

2. Group Operation Preservation: For any $g_{1},g_{2}\in G$,

$\mathrm{Ad}_{g_{1}g_{2}}(X)=(g_{1}g_{2})X(g_{1}g_{2})^{-1}=g_{1}(g_{2}Xg_{2}^{-1})g_{1}^{-1}=\mathrm{Ad}_{g_{1}}(\mathrm{Ad}_{g_{2}}(X))$

This shows that $\mathrm{Ad}_{g_{1}g_{2}}=\mathrm{Ad}_{g_{1}}\circ\mathrm{Ad}_{g_{2}}$.  
3. Continuity: Let $\{g_{n}\}$ be a sequence in $G$ converging to a limit $g$. Because standard matrix multiplication and matrix inversion are continuous operations, we can pass the limit inside:

$\lim_{n\to\infty}\mathrm{Ad}_{g_{n}}(X)=\lim_{n\to\infty}(g_{n}Xg_{n}^{-1})=gXg^{-1}=\mathrm{Ad}_{g}(X)$

Thus, the map $g\mapsto\mathrm{Ad}_{g}$ is continuous.  
4. Bracket Preservation: Using the matrix commutator $[X,Y]=XY-YX$,

$\mathrm{Ad}_{g}([X,Y])$ $=g(XY-YX)g^{-1}$  
$=gXYg^{-1}-gYXg^{-1}$

By inserting the identity $I=g^{-1}g$ into the middle of each term, we get:

$(gXg^{-1})(gYg^{-1})-(gYg^{-1})(gXg^{-1})$ $=\mathrm{Ad}_{g}(X)\,\mathrm{Ad}_{g}(Y)-\mathrm{Ad}_{g}(Y)\,\mathrm{Ad}_{g}(X)$  
$=[\mathrm{Ad}_{g}(X),\mathrm{Ad}_{g}(Y)]$

∎

### The Associated Lie Algebra Homomorphism (ad)

The Lie group homomorphism $\mathrm{Ad}:G\to GL(\mathfrak{g})$ induces an associated Lie algebra homomorphism, denoted as $\mathrm{ad}$. This is the derivative of $\mathrm{Ad}$ evaluated at the identity:

$\mathrm{ad}:\mathfrak{g}\to\mathfrak{gl}(\mathfrak{g})=M(k,\mathbb{R})$

(where $k=\dim(\mathfrak{g})$)

Key Properties:  
For all $X,Y\in\mathfrak{g}$, the $\mathrm{ad}$ homomorphism satisfies:

1. $e^{\mathrm{ad}_{X}}=\mathrm{Ad}_{e^{X}}$
2. $\mathrm{ad}_{[X,Y]}=[\mathrm{ad}_{X},\mathrm{ad}_{Y}]$

Deriving $\mathrm{ad}_{X}(Y)$:  
We can find the explicit formula for the ”little adjoint” action by differentiating the ”big Adjoint” action with respect to $t$ at $t=0$:

$\mathrm{ad}_{X}(Y)=\left.\frac{d}{dt}\right|_{t=0}\mathrm{Ad}_{e^{tX}}(Y)=\left.\frac{d}{dt}\right|_{t=0}e^{tX}Ye^{-tX}=[X,Y]$

---

This identity gives rise to a highly useful power series expansion for the Adjoint action of an exponential:

$\mathrm{Ad}_{e^{X}}(Y)=e^{X}Ye^{-X}=e^{\mathrm{ad}_{X}}(Y)=Y+[X,Y]+\frac{1}{2!}[X,[X,Y]]+\ldots$

The Commutative Diagram:  
The relationship between the Lie group $G$, its Lie algebra $\mathfrak{g}$, and their respective adjoint representations is elegantly summarized by the following commutative diagram (where the vertical maps represent the exponential map):

The Adjoint Representation of $SU(d)$

Let us focus on the special unitary group $G=SU(d)$. Its Lie algebra $\mathfrak{g}=\mathfrak{su}(d)$ is the real vector space of skew-Hermitian, traceless matrices:

$\mathfrak{g}=\mathfrak{su}(d)=\{X\in M(d,\mathbb{C})\mid X^{\dagger}=-X,\mathrm{tr}(X)=0\}$

The dimension of this space is $\dim_{\mathbb{R}}\mathfrak{su}(d)=d^{2}-1$.

There is a natural inner product on $\mathfrak{g}$ called the Hilbert-Schmidt inner product, defined as:

$(X|Y)_{H-S}=d\,\mathrm{tr}\big{(}X^{\dagger}Y\big{)}=-d\,\mathrm{tr}(XY)$

(Note: Since $X\in\mathfrak{su}(d)$, $X^{\dagger}=-X$, which allows us to pull out the negative sign).

### 6.1 Orthogonality of the Adjoint Action

For every $U\in SU(d)$, the adjoint map $\mathrm{Ad}_{U}(X)=UXU^{-1}$ acts as an orthogonal transformation on the Lie algebra. To see this, we can verify that $\mathrm{Ad}_{U}$ preserves the inner product. For any $X,Y\in\mathfrak{su}(d)$:

$(\mathrm{Ad}_{U}(X)|\,\mathrm{Ad}_{U}(Y))_{H-S}$ $=-d\,\mathrm{tr}\big{(}UXU^{-1}UYU^{-1}\big{)}$  
$=-d\,\mathrm{tr}\big{(}UXYU^{-1}\big{)}$

Using the cyclic property of the trace ($\mathrm{tr}(AB)=\mathrm{tr}(BA)$):

$-d\,\mathrm{tr}\big{(}UXYU^{-1}\big{)}$ $=-d\,\mathrm{tr}\big{(}U^{-1}UXY\big{)}$  
$=-d\,\mathrm{tr}(XY)$  
$=(X|Y)_{H-S}$

---

Because the inner product is preserved, $\mathrm{Ad}_U \in SO(\mathfrak{g})$. Consequently, the Adjoint representation is a map from the Lie group to the special orthogonal group of its Lie algebra:

$$
\operatorname{Ad}: SU(d) \to SO(\mathfrak{su}(d)) \cong SO(d^2 - 1)
$$

## 6.2 Explicit Matrix Elements

Let $\{\gamma_1, \gamma_2, \dots, \gamma_{d^2 - 1}\}$ be an orthonormal basis for $\mathfrak{su}(d)$ with respect to the Hilbert-Schmidt inner product, meaning $(\gamma_i | \gamma_j)_{H - S} = \delta_{ij}$. The matrix elements of the operator $\mathrm{Ad}_U$ in this basis are given by:

$$
[\mathrm{Ad}_U]_{ij} = (\gamma_i | \mathrm{Ad}_U(\gamma_j))_{H - S} = (\gamma_i | U\gamma_jU^{-1})_{H - S} = -d \operatorname{tr}(\gamma_i U\gamma_jU^{-1})
$$

If we denote this $(d^2 - 1) \times (d^2 - 1)$ matrix simply by $\mathrm{Ad}_U$, the orthogonality proven above guarantees that it satisfies:

$$
\mathrm{Ad}_U^T \cdot \mathrm{Ad}_U = I = \mathrm{Ad}_U \cdot \mathrm{Ad}_U^T
$$

## 7 The Case of $SU(2)$ and Pauli Matrices

Let us focus on the case where $d = 2$. Here, $G = SU(2)$ and its Lie algebra is:

$$
\mathfrak{su}(2) = \{X \in M(2, \mathbb{C}) \mid X^\dagger = -X, \operatorname{tr}(X) = 0\}
$$

## 7.1 The Pauli Matrices

First, we look at the general Hermitian Pauli matrices:

$$
\sigma_x = \sigma_1 = \begin{pmatrix} 0 & 1 \\ 1 & 0 \end{pmatrix}, \quad \sigma_y = \sigma_2 = \begin{pmatrix} 0 & -i \\ i & 0 \end{pmatrix}, \quad \sigma_z = \sigma_3 = \begin{pmatrix} 1 & 0 \\ 0 & -1 \end{pmatrix}, \quad \sigma_0 = I = \begin{pmatrix} 1 & 0 \\ 0 & 1 \end{pmatrix}
$$

Let $\epsilon_{ijk}$ be the completely antisymmetric Levi-Civita tensor for $i, j, k \in \{1, 2, 3\}$:

$$
\epsilon_{123} = \epsilon_{231} = \epsilon_{312} = 1 = -\epsilon_{213} = -\epsilon_{132} = -\epsilon_{321}
$$

and $\epsilon_{ijk} = 0$ otherwise.

**Fact** (Algebraic properties of Pauli matrices).

- **Multiplication**: $\sigma_j \sigma_k = \delta_{jk} I + i \sum_l \epsilon_{jkl} \sigma_l$
- **Self-Adjoint**  **&**  **Unitary**: $\sigma_j^\dagger = \sigma_j$ and $\sigma_j^\dagger \sigma_j = I$
- **Commutator**: $[\sigma_j, \sigma_k] = 2i \sum_l \epsilon_{jkl} \sigma_l$
- **Anti-commutator**: $\{\sigma_j, \sigma_k\} = 2\delta_{jk}I$

---

7.2 The Lie Algebra $\mathfrak{su}(2)$

Define $\tilde{\sigma}_k = -\frac{i}{2}\sigma_k$. These matrices are anti-Hermitian, and their commutator relationship is:

$$
[ \tilde {\sigma} _ {j}, \tilde {\sigma} _ {k} ] = \sum_ {l} \epsilon_ {j k l} \tilde {\sigma} _ {l}
$$

We can write the respective Lie algebras as spans of these matrices:

$$
\mathfrak {s u} (2) = \operatorname {S p a n} _ {\mathbb {R}} \left\{\tilde {\sigma} _ {1}, \tilde {\sigma} _ {2}, \tilde {\sigma} _ {3} \right\} \quad \text {and} \quad \mathfrak {u} (2) = \operatorname {S p a n} _ {\mathbb {R}} \left\{\tilde {\sigma} _ {0}, \tilde {\sigma} _ {1}, \tilde {\sigma} _ {2}, \tilde {\sigma} _ {3} \right\}
$$

The matrices $\tilde{\sigma}_k$ form an orthonormal basis. For example:

$$
- 2 \operatorname {t r} \left(\tilde {\sigma} _ {k} \tilde {\sigma} _ {k}\right) = - 2 \left(- \frac {i}{2}\right) ^ {2} \operatorname {t r} \left(\sigma_ {k} ^ {2}\right) = - 2 \left(- \frac {1}{4}\right) \cdot 2 = 1
$$

And for $k\neq j$:

$$
- 2 \operatorname {t r} \left(\tilde {\sigma} _ {j} \tilde {\sigma} _ {k}\right) = - 2 \left(- \frac {i}{2}\right) ^ {2} \operatorname {t r} \left(\sigma_ {j} \sigma_ {k}\right) = \frac {1}{2} i \epsilon_ {j k l} \operatorname {t r} \left(\sigma_ {l}\right) = 0
$$

8 Isomorphism between $\mathfrak{su}(2)$ and $\mathbb{R}^3$

For any vector $\vec{a} = (a_{1}, a_{2}, a_{3}) \in \mathbb{R}^{3}$, we define $\vec{a} \cdot \hat{\vec{\sigma}} = a_{1} \tilde{\sigma}_{1} + a_{2} \tilde{\sigma}_{2} + a_{3} \tilde{\sigma}_{3}$. The standard inner product and cross product in $\mathbb{R}^{3}$ are given by:

$$
(\vec {a} | \vec {b}) = \vec {a} \cdot \vec {b} = a _ {1} b _ {1} + a _ {2} b _ {2} + a _ {3} b _ {3}, \qquad \vec {a} \times \vec {b} = \det  \left( \begin{array}{c c c} \hat {i} & \hat {j} & \hat {k} \\ a _ {1} & a _ {2} & a _ {3} \\ b _ {1} & b _ {2} & b _ {3} \end{array} \right)
$$

8.1 The Isomorphism

The map $\mathbb{R}^3 \ni \vec{a} \mapsto \vec{a} \cdot \hat{\vec{\sigma}} \in \mathfrak{su}(2)$ is an isomorphism of Lie algebras that precisely preserves the inner product structure:

1. $(\vec{a}\cdot \hat{\vec{\sigma}} |\vec{b}\cdot \hat{\vec{\sigma}})_{H - S} = \vec{a}\cdot \vec{b}$
2. $[\vec{a}\cdot \hat{\vec{\sigma}},\vec{b}\cdot \hat{\vec{\sigma}} ] = (\vec{a}\times \vec{b})\cdot \hat{\vec{\sigma}}$

Thus, we can physically and geometrically identify $\mathfrak{su}(2)$ with standard $\mathbb{R}^3$.

8.2 Exponentiating to the Group

Any special unitary matrix $U \in SU(2)$ can be written as $U = e^{\alpha \hat{n} \cdot \hat{\vec{\sigma}}}$ where $\hat{n} \in \mathbb{R}^3$ is a unit vector ($|\hat{n}| = 1$). The Adjoint action is given by:

$$
\mathrm {A d} _ {U} = \mathrm {A d} _ {e ^ {\alpha \hat {n} \cdot \hat {\vec {\sigma}}}} = e ^ {\mathrm {a d} _ {\alpha \hat {n} \cdot \hat {\vec {\sigma}}}}
$$

---

Evaluating the adjoint generator $\mathrm{ad}_{\alpha \hat{n}\cdot \hat{\vec{\sigma}}} = \alpha [n_1\mathrm{ad}_{\hat{\sigma}_1} + n_2\mathrm{ad}_{\hat{\sigma}_2} + n_3\mathrm{ad}_{\hat{\sigma}_3}]$, we can define the matrix representations $O_{k}$ of the $\mathrm{ad}_{\hat{\sigma}_k}$ operators:

$$
O _ {1} = \left( \begin{array}{c c c} 0 & 0 & 0 \\ 0 & 0 & - 1 \\ 0 & 1 & 0 \end{array} \right), \quad O _ {2} = \left( \begin{array}{c c c} 0 & 0 & 1 \\ 0 & 0 & 0 \\ - 1 & 0 & 0 \end{array} \right), \quad O _ {3} = \left( \begin{array}{c c c} 0 & - 1 & 0 \\ 1 & 0 & 0 \\ 0 & 0 & 0 \end{array} \right)
$$

Notice that $\operatorname{Span}_{\mathbb{R}}\{O_1,O_2,O_3\} = \mathfrak{so}(3)\cong \mathfrak{su}(2)$, and $[O_j,O_k] = \sum_l\epsilon_{jkl}O_l$. We can write $\mathrm{ad}_{\alpha \hat{n}\cdot \hat{\vec{\sigma}}} = \alpha \hat{n}\cdot \vec{O}$.

This gives us the corresponding rotation matrix:

$$
\mathrm {A d} _ {e ^ {\alpha \hat {n} \cdot \hat {\vec {\sigma}}}} = e ^ {\alpha \hat {n} \cdot \vec {O}} \in S O (3)
$$

$$
\mathrm {A d} _ {e ^ {\alpha \hat {n} \cdot \hat {\vec {\sigma}}}} [ \vec {a} \cdot \hat {\vec {\sigma}} ] = \left[ (e ^ {\alpha \hat {n} \cdot \vec {a}}) \vec {a} \right] \cdot \hat {\vec {\sigma}}
$$

This represents a geometric rotation in $\mathbb{R}^3$ around the axis $\hat{n}$ by an angle $\alpha$. In fact, $\operatorname{Ad}: SU(2) \to SO(3)$ is a 2-to-1 surjective map (both $U$ and $-U$ map to the exact same rotation).

## 8.3 Explicit Formula for $e^{\alpha \hat{n} \cdot \hat{\vec{\sigma}}}$

Assume a matrix satisfies $A^2 = I$. Using the Taylor series expansion, we can prove a matrix version of Euler's formula:

$$
e ^ {i \alpha A} = \sum_ {n = 0} ^ {\infty} \frac {(i \alpha) ^ {n}}{n !} A ^ {n} = \sum_ {k = 0} ^ {\infty} \frac {i ^ {2 k} \alpha^ {2 k}}{(2 k) !} I + \sum_ {k = 0} ^ {\infty} \frac {i ^ {2 k + 1} \alpha^ {2 k + 1}}{(2 k + 1) !} A = \cos (\alpha) I + i \sin (\alpha) A
$$

Applying this identity to $\hat{\vec{\sigma}} = -\frac{i}{2}\vec{\sigma}$:

$$
e ^ {\alpha \hat {n} \cdot \hat {\vec {\sigma}}} = e ^ {- i \frac {\alpha}{2} \hat {n} \cdot \vec {\sigma}} = \cos \left(\frac {\alpha}{2}\right) I - i \sin \left(\frac {\alpha}{2}\right) \hat {n} \cdot \vec {\sigma}
$$

Note the resulting half-angle $\frac{\alpha}{2}$. Because of this factor, to achieve a full rotation mapping the space back to its original state, $\alpha$ must range from $[0,4\pi]$ rather than $[0,2\pi]$.

## 9 Qubits and the Bloch Sphere

Qubits: A quantum system described by a 2-dimensional Hilbert space is called a qubit (analogous to a $d$-dimensional qudit). We choose an orthonormal basis $\{|0\rangle, |1\rangle\}$ as the analog to classical logical bits 0 and 1. These are defined as the eigenstates of $\sigma_{3}$ with eigenvalues 1 and $-1$, respectively.

## 9.1 Parametrizing Qubit Mixed States

Any Hermitian $2 \times 2$ matrix can be written as a linear combination of the identity and the Pauli matrices: $a_0 I + \vec{a} \cdot \vec{\sigma}$.

---

For this matrix to represent a valid physical density matrix  $\rho$ , it must have a unit trace:

$$
\operatorname {t r} \left(a _ {0} I + \vec {a} \cdot \vec {\sigma}\right) = 1 \Longrightarrow \operatorname {t r} \left(a _ {0} I\right) = 1 \Longrightarrow a _ {0} = \frac {1}{2}
$$

Thus, the density matrix takes the form:

$$
\rho = \frac {1}{2} (I + \vec {x} \cdot \vec {\sigma})
$$

The eigenvalues of this matrix are  $q_{1,2} = \frac{1}{2} \pm \frac{1}{2} |\vec{x}|$ . To ensure the state is positive semi-definite (i.e., the probabilities  $q_i \geq 0$ ), we must require  $|\vec{x}| \leq 1$ . Therefore, all mixed states of a qubit are parametrized by real vectors  $\vec{x} \in \mathbb{R}^3$  that lie within or on the unit sphere.

**Fact.**  States lying exactly on the boundary, where  $|\vec{x}| = 1$ , are pure states.

**Proof.**  Recall the Pauli vector identity:  $(\vec{a} \cdot \vec{\sigma})(\vec{b} \cdot \vec{\sigma}) = (\vec{a} \cdot \vec{b})I + i(\vec{a} \times \vec{b}) \cdot \vec{\sigma}$ . Setting  $\vec{a} = \vec{b} = \vec{x}$ , we obtain  $(\vec{x} \cdot \vec{\sigma})^2 = |\vec{x}|^2 I$ .

Now, we square the density matrix:

$$
\rho_ {\vec {x}} ^ {2} = \frac {1}{4} (I + \vec {x} \cdot \vec {\sigma}) ^ {2} = \frac {1}{4} (I + 2 \vec {x} \cdot \vec {\sigma} + | \vec {x} | ^ {2} I) = \frac {1}{4} \left((1 + | \vec {x} | ^ {2}) I + 2 \vec {x} \cdot \vec {\sigma}\right)
$$

If  $|\vec{x}| = 1$ , this expression simplifies to:

$$
\rho_ {\vec {x}} ^ {2} = \frac {1}{4} (2 I + 2 \vec {x} \cdot \vec {\sigma}) = \frac {1}{2} (I + \vec {x} \cdot \vec {\sigma}) = \rho_ {\vec {x}}
$$

Since  $\rho = \rho^2$ , the matrix is idempotent, confirming it represents a pure state.

## 9.2 The Bloch Sphere Representation

The geometric interpretation of this parametrization is the Bloch sphere.

![img-0.jpeg](assets/ocr-20260421194049-9erjdxd.png)

---

10 Operations on Qubits

Any unitary $2\times 2$ operator can be decomposed into a global phase and a special unitary rotation:

$U_{full}=e^{i\phi}e^{\alpha\hat{n}\cdot\tilde{\vec{\sigma}}}=e^{i\phi}U$

where $e^{i\phi}$ is the global phase factor and $U=e^{\alpha\hat{n}\cdot\tilde{\vec{\sigma}}}\in SU(2)$. Notice that the determinant is strictly 1: $\det(U)=\det\Big{(}e^{\alpha\hat{n}\cdot\tilde{\vec{\sigma}}}\Big{)}=e^{\alpha\operatorname{tr}\big{(}\hat{n}\cdot\tilde{\vec{\sigma}}\big{)}} =e^{0}=1$.

A unitary operator acts on a mixed state via conjugation. In this process, the global phase factor neatly cancels out:

$(e^{i\phi}U)\rho(e^{i\phi}U)^{\dagger}=U\rho U^{\dagger}$

Because $U^{\dagger}=U^{-1}$, this operation is exactly the Adjoint action $\mathrm{Ad}_{U}$:

$\mathrm{Ad}_{U}(\rho_{\vec{x}})$ $=\mathrm{Ad}_{U}\left(\frac{1}{2}I+\frac{1}{2}\vec{x}\cdot\vec{\sigma}\right)$  
$=\frac{1}{2}\,\mathrm{Ad}_{U}(I)+\frac{1}{2}\,\mathrm{Ad}_{U}(\vec{x}\cdot\vec{\sigma})$  
$=\frac{1}{2}I+\frac{1}{2}\left[\big{(}e^{\alpha\hat{n}\cdot\vec{\sigma}}\big{)}\,\vec{x}\right]\cdot\vec{\sigma}$

Geometrically, this maps to a pure 3D rotation of the Bloch vector $\vec{x}$ by an angle $\alpha$ around the unit axis $\hat{n}$.

## 11 Generalization: Qudits

This entire framework naturally generalizes to $d$-level quantum systems, known as qudits, where the Hilbert space is $\mathcal{H}=\mathbb{C}^{d}$.

Let $\{\gamma_{1},\ldots,\gamma_{d^{2}-1}\}$ be an orthonormal basis of $\mathfrak{su}(d)$. Any generic state can be written as:

$\rho=a_{0}I+i\vec{a}\cdot\vec{\gamma}$

For the trace constraint $\operatorname{tr}(\rho)=1$ to hold, we must have $a_{0}=\frac{1}{d}$. This yields the generalized state equation:

$\rho=\frac{1}{d}[I+i\vec{x}\cdot\vec{\gamma}]$

where the generalized Bloch vector $\vec{x}\in\mathbb{R}^{d^{2}-1}$ is bounded by the strict requirement that the density matrix remains positive semi-definite ($\rho\geq 0$).

The Adjoint action of a unitary operator $U$ on a qudit state behaves identically:

$\mathrm{Ad}_{U}(\rho)=\frac{1}{d}I+\frac{1}{d}\,\mathrm{Ad}_{U}(\vec{x}\cdot\vec{\gamma})=\frac{1}{d}I+\frac{i}{d}[\mathrm{Ad}_{U}(\vec{x})]\cdot\vec{\gamma}=\frac{1}{d}[I+i\,\mathrm{Ad}_{U}(\vec{x})\cdot\vec{\gamma}]$

where $\mathrm{Ad}_{U}(\vec{x})$ now represents a high-dimensional rotation drawn from $SO(d^{2}-1)$ and

$[\mathrm{Ad}_{U}]_{ij}=(\gamma_{i}|\,\mathrm{Ad}_{U}(\gamma_{j}))_{H-S}=(\gamma_{i} |U\gamma_{j}U^{-1})_{H-S}=-d\operatorname{tr}\big{(}\gamma_{i}U\gamma_{j}U^{-1}\big {)}$

where
