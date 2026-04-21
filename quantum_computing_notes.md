---
title: quantum_computing (11)
date: 2026-04-21T19:40:49+08:00
lastmod: 2026-04-21T20:45:00+08:00
---

# quantum_computing (11)

## Introduction to Quantum Computing

Adam Sawicki

2026

These notes rewrite the quantum computing material in a more formal structure. The guiding principle is:

1. state the object clearly,
2. isolate the exact theorem being used,
3. only then perform the computation.

In particular, the notation is organized so that the transition

- from vectors $|\psi\rangle$ to density matrices $\rho$,
- from matrices to Lie algebras,
- and from $SU(2)$ to rotations in $\mathbb{R}^{3}$

always happens in clearly marked steps.

## 1. Quantum Mechanics as the Starting Point

### 1.1 States, observables, and measurement

**Postulate (States).** A finite-dimensional quantum system is described by a Hilbert space $\mathcal{H}$. A pure state is represented by a unit vector $|\psi\rangle \in \mathcal{H}$ with $\langle \psi | \psi \rangle = 1$.

**Remark.** Two unit vectors that differ only by a global phase represent the same physical pure state:

$$
|\psi\rangle \sim e^{i\theta}|\psi\rangle.
$$

Hence pure states are physically rays in $\mathcal{H}$, not individual vectors.

**Postulate (Observables).** A measurable quantity is represented by a Hermitian operator $F : \mathcal{H} \to \mathcal{H}$.

If

$$
F = \sum_{\lambda \in \sigma(F)} \lambda P_{\lambda}
$$

is its spectral decomposition, then the possible outcomes of measuring $F$ are precisely the eigenvalues $\lambda \in \sigma(F)$.

**Postulate (Born rule).** If the system is in the pure state $|\psi\rangle$, then the probability of obtaining the outcome $\lambda$ when measuring $F$ is

$$
\mathbb{P}_{\psi}(\lambda) = \langle \psi | P_{\lambda} | \psi \rangle = \|P_{\lambda}|\psi\rangle\|^{2}.
$$

**Remark.** Since $\sum_{\lambda} P_{\lambda} = I$, the Born rule defines a probability measure:

$$
\sum_{\lambda \in \sigma(F)} \mathbb{P}_{\psi}(\lambda)
= \sum_{\lambda} \langle \psi | P_{\lambda} | \psi \rangle
= \langle \psi | I | \psi \rangle
= 1.
$$

**Definition (Expectation value).** The expectation value of $F$ in the state $|\psi\rangle$ is

$$
\langle F \rangle_{\psi} := \langle \psi | F | \psi \rangle.
$$

**Lemma.** With the above notation,

$$
\langle F \rangle_{\psi} = \sum_{\lambda \in \sigma(F)} \lambda \, \mathbb{P}_{\psi}(\lambda).
$$

**Proof.**

$$
\langle F \rangle_{\psi}
= \left\langle \psi \left| \sum_{\lambda} \lambda P_{\lambda} \right| \psi \right\rangle
= \sum_{\lambda} \lambda \langle \psi | P_{\lambda} | \psi \rangle
= \sum_{\lambda} \lambda \, \mathbb{P}_{\psi}(\lambda).
$$

$\square$

**Postulate (State collapse).** If a measurement of $F$ gives the outcome $\lambda$, then the post-measurement state is

$$
|\psi\rangle \longmapsto \frac{P_{\lambda}|\psi\rangle}{\|P_{\lambda}|\psi\rangle\|}.
$$

**Remark.** If $|\psi\rangle$ is already an eigenvector of $F$ with eigenvalue $\lambda$, then the outcome $\lambda$ occurs with probability $1$ and the state does not change except for normalization, which is already satisfied.

### 1.2 Uncertainty and compatible observables

**Definition (Variance and uncertainty).** For an observable $F$, define

$$
\Delta_{\psi}(F)^{2}
:= \left\langle \psi \left| \left(F - \langle F \rangle_{\psi} I\right)^{2} \right| \psi \right\rangle.
$$

Then $\Delta_{\psi}(F)$ is the uncertainty of $F$ in the state $|\psi\rangle$.

**Lemma.**

$$
\Delta_{\psi}(F)^{2} = \langle F^{2} \rangle_{\psi} - \langle F \rangle_{\psi}^{2}.
$$

**Proof.**

$$
\begin{aligned}
\Delta_{\psi}(F)^{2}
&= \langle \psi | (F - \langle F \rangle_{\psi} I)^{2} | \psi \rangle \\
&= \langle \psi | F^{2} | \psi \rangle
- 2 \langle F \rangle_{\psi} \langle \psi | F | \psi \rangle
+ \langle F \rangle_{\psi}^{2} \langle \psi | \psi \rangle \\
&= \langle F^{2} \rangle_{\psi} - \langle F \rangle_{\psi}^{2}.
\end{aligned}
$$

$\square$

**Lemma.** $\Delta_{\psi}(F)=0$ if and only if $|\psi\rangle$ is an eigenvector of $F$.

**Proof.** We have

$$
\Delta_{\psi}(F)^{2}
= \|(F - \langle F \rangle_{\psi} I)|\psi\rangle\|^{2}.
$$

Thus $\Delta_{\psi}(F)=0$ if and only if

$$
(F - \langle F \rangle_{\psi} I)|\psi\rangle = 0,
$$

which is exactly the eigenvalue equation.

$\square$

**Definition (Compatibility).** Two observables $F$ and $G$ are called compatible if

$$
[F,G] := FG - GF = 0.
$$

**Remark.** In finite dimensions, $[F,G]=0$ implies that $F$ and $G$ can be simultaneously diagonalized. In that basis, there are states with zero uncertainty for both observables at the same time.

**Theorem (Robertson-Schr\"odinger uncertainty relation).** Let

$$
\widehat{F} := F - \langle F \rangle_{\psi} I,
\qquad
\widehat{G} := G - \langle G \rangle_{\psi} I.
$$

Then

$$
\Delta_{\psi}(F)^{2}\Delta_{\psi}(G)^{2}
\geq
\frac{1}{4}\langle \{\widehat{F},\widehat{G}\} \rangle_{\psi}^{2}
+
\frac{1}{4}\left| \langle [F,G] \rangle_{\psi} \right|^{2},
$$

where $\{A,B\} := AB + BA$.

**Proof.** Set

$$
|f\rangle := \widehat{F}|\psi\rangle,
\qquad
|g\rangle := \widehat{G}|\psi\rangle.
$$

By Cauchy-Schwarz,

$$
\Delta_{\psi}(F)^{2}\Delta_{\psi}(G)^{2}
= \|f\|^{2}\|g\|^{2}
\geq |\langle f | g \rangle|^{2}
= |\langle \psi | \widehat{F}\widehat{G} | \psi \rangle|^{2}.
$$

Now decompose

$$
\widehat{F}\widehat{G}
= \frac{1}{2}\{\widehat{F},\widehat{G}\}
+ \frac{1}{2}[\widehat{F},\widehat{G}].
$$

The expectation of the anticommutator is real, while the expectation of the commutator is purely imaginary. Therefore,

$$
|\langle \widehat{F}\widehat{G} \rangle_{\psi}|^{2}
=
\frac{1}{4}\langle \{\widehat{F},\widehat{G}\} \rangle_{\psi}^{2}
+
\frac{1}{4}\left| \langle [\widehat{F},\widehat{G}] \rangle_{\psi} \right|^{2}.
$$

Finally, since scalar multiples of the identity commute with everything,

$$
[\widehat{F},\widehat{G}] = [F,G].
$$

$\square$

**Remark.** The term involving the anticommutator plays the role of a quantum covariance term, while the commutator term is the genuinely non-classical contribution.

## 2. Time Evolution

### 2.1 Schr\"odinger evolution

**Postulate (Unitary time evolution).** Let $t_{0}$ be an initial time. For a closed quantum system there exists a time-evolution operator $U(t,t_{0})$ such that

$$
|\psi(t)\rangle = U(t,t_{0})|\psi(t_{0})\rangle.
$$

It satisfies the Schr\"odinger equation

$$
i \frac{d}{dt}U(t,t_{0}) = H(t)U(t,t_{0}),
\qquad
U(t_{0},t_{0}) = I,
$$

where $H(t)$ is the Hamiltonian.

Applying this to $|\psi(t_{0})\rangle$ gives the state equation

$$
i \frac{d}{dt}|\psi(t)\rangle = H(t)|\psi(t)\rangle.
$$

**Theorem.** If $H(t)$ is Hermitian for all $t$, then $U(t,t_{0})$ is unitary for all $t$.

**Proof.** From the Schr\"odinger equation,

$$
\frac{d}{dt}U(t,t_{0}) = -iH(t)U(t,t_{0}).
$$

Taking adjoints gives

$$
\frac{d}{dt}U(t,t_{0})^{\dagger} = iU(t,t_{0})^{\dagger}H(t).
$$

Hence

$$
\begin{aligned}
\frac{d}{dt}\left(U^{\dagger}U\right)
&= \left(\frac{d}{dt}U^{\dagger}\right)U + U^{\dagger}\left(\frac{d}{dt}U\right) \\
&= iU^{\dagger}HU - iU^{\dagger}HU \\
&= 0.
\end{aligned}
$$

Therefore $U^{\dagger}U$ is constant in time. At $t=t_{0}$,

$$
U(t_{0},t_{0})^{\dagger}U(t_{0},t_{0}) = I,
$$

so $U^{\dagger}U=I$ for all $t$.

$\square$

### 2.2 Time-independent Hamiltonians

**Example (Time-independent Hamiltonian).** If $H$ does not depend on time and $t_{0}=0$, then

$$
U(t) = e^{-itH},
\qquad
|\psi(t)\rangle = e^{-itH}|\psi(0)\rangle.
$$

If

$$
H = \sum_{k} E_{k} P_{E_{k}},
$$

then

$$
e^{-itH} = \sum_{k} e^{-itE_{k}} P_{E_{k}},
$$

and therefore

$$
|\psi(t)\rangle = \sum_{k} e^{-itE_{k}} P_{E_{k}}|\psi(0)\rangle.
$$

**Remark (Stationary states).** If $|\psi(0)\rangle$ is an energy eigenstate with eigenvalue $E$, then

$$
|\psi(t)\rangle = e^{-itE}|\psi(0)\rangle.
$$

This is only a global phase, so all physical predictions remain unchanged.

### 2.3 One-parameter unitary groups

**Theorem (Finite-dimensional Stone theorem).** Let $U(t)$ be a continuous one-parameter unitary group:

$$
U(0)=I,
\qquad
U(t+s)=U(t)U(s).
$$

Assume $U'(0)$ exists. Then there exists a unique Hermitian operator $H$ such that

$$
U(t)=e^{-itH}.
$$

**Proof.** Let

$$
A := U'(0).
$$

Using $U(t+s)=U(t)U(s)$,

$$
\frac{d}{dt}U(t)
= \lim_{s\to 0}\frac{U(t+s)-U(t)}{s}
= U(t)\lim_{s\to 0}\frac{U(s)-I}{s}
= U(t)A.
$$

Thus $U(t)=e^{tA}$. Since $U(t)$ is unitary,

$$
U(t)^{\dagger} = U(-t),
$$

so

$$
e^{tA^{\dagger}} = e^{-tA}.
$$

Differentiating at $t=0$ gives $A^{\dagger}=-A$, so $A$ is anti-Hermitian. Therefore $A=-iH$ for a unique Hermitian $H$, and

$$
U(t)=e^{-itH}.
$$

$\square$

**Remark.** In full functional analysis, strong continuity is the correct general assumption. In finite dimensions, the simplified version above is enough.

## 3. Mixed States

### 3.1 From ensembles to density operators

**Definition (Statistical ensemble).** Suppose the system is prepared in pure states $|\psi_{k}\rangle$ with classical probabilities $p_{k}$, where $p_{k}\geq 0$ and $\sum_{k} p_{k}=1$. The collection

$$
\{(p_{k},|\psi_{k}\rangle)\}
$$

is called an ensemble.

**Definition (Density operator).** The density operator associated with the ensemble is

$$
\rho := \sum_{k} p_{k} |\psi_{k}\rangle\langle \psi_{k}|.
$$

> 💡 **Recall (Quantum Foundations):** In your QF notes, pure states were repeatedly identified with rank-$1$ projectors $|\psi\rangle\langle\psi|$. The density matrix is the same object after adding classical uncertainty: it is a convex combination of those rank-$1$ projectors.

**Lemma (Measurement probabilities for mixed states).** If $F=\sum_{\lambda}\lambda P_{\lambda}$ is an observable and the system is in the mixed state $\rho$, then

$$
\mathbb{P}_{\rho}(\lambda) = \operatorname{tr}(\rho P_{\lambda}).
$$

**Proof.** By the law of total probability,

$$
\mathbb{P}_{\rho}(\lambda)
= \sum_{k} p_{k}\mathbb{P}_{\psi_{k}}(\lambda)
= \sum_{k} p_{k}\langle \psi_{k}|P_{\lambda}|\psi_{k}\rangle.
$$

Using $\operatorname{tr}(|u\rangle\langle v|A)=\langle v|A|u\rangle$,

$$
\sum_{k} p_{k}\langle \psi_{k}|P_{\lambda}|\psi_{k}\rangle
= \sum_{k} p_{k}\operatorname{tr}(|\psi_{k}\rangle\langle\psi_{k}|P_{\lambda})
= \operatorname{tr}\left(\sum_{k} p_{k} |\psi_{k}\rangle\langle\psi_{k}| P_{\lambda}\right)
= \operatorname{tr}(\rho P_{\lambda}).
$$

$\square$

**Corollary (Expectation value).**

$$
\langle F \rangle_{\rho} = \operatorname{tr}(\rho F).
$$

**Proof.**

$$
\langle F \rangle_{\rho}
= \sum_{\lambda} \lambda \, \mathbb{P}_{\rho}(\lambda)
= \sum_{\lambda} \lambda \, \operatorname{tr}(\rho P_{\lambda})
= \operatorname{tr}\left(\rho \sum_{\lambda}\lambda P_{\lambda}\right)
= \operatorname{tr}(\rho F).
$$

$\square$

### 3.2 Post-measurement states

**Theorem (Projective measurement update for mixed states).** Let $F=\sum_{\lambda}\lambda P_{\lambda}$ and assume the measurement outcome is $\lambda$. Then the post-measurement state is

$$
\rho_{\lambda}
= \frac{P_{\lambda}\rho P_{\lambda}}{\operatorname{tr}(\rho P_{\lambda})}.
$$

**Remark.** This is the density-matrix version of state collapse. The denominator is exactly the probability of obtaining the outcome $\lambda$.

### 3.3 Characterization of density operators

**Definition.** The set of all states on $\mathcal{H}$ is denoted by

$$
\mathcal{D}(\mathcal{H})
= \{\rho \in \mathcal{L}(\mathcal{H}) : \rho \geq 0,\ \operatorname{tr}(\rho)=1\}.
$$

**Theorem.** An operator $\rho$ is a density operator if and only if

1. $\rho \geq 0$,
2. $\operatorname{tr}(\rho)=1$.

**Proof.**

- If $\rho=\sum_{k}p_{k}|\psi_{k}\rangle\langle\psi_{k}|$, then clearly $\rho\geq 0$ and

$$
\operatorname{tr}(\rho)
= \sum_{k} p_{k}\operatorname{tr}(|\psi_{k}\rangle\langle\psi_{k}|)
= \sum_{k} p_{k}
= 1.
$$

- Conversely, if $\rho\geq 0$ and $\operatorname{tr}(\rho)=1$, then the spectral theorem gives

$$
\rho = \sum_{k=1}^{d}\lambda_{k}|e_{k}\rangle\langle e_{k}|,
$$

with $\lambda_{k}\geq 0$ and $\sum_{k}\lambda_{k}=1$. Hence $\rho$ is the ensemble

$$
\{(\lambda_{k},|e_{k}\rangle)\}.
$$

$\square$

**Remark (Observational equivalence).** Two density matrices $\rho_{1}$ and $\rho_{2}$ describe the same physical state if and only if they give the same expectation value for every observable:

$$
\operatorname{tr}(\rho_{1}F)=\operatorname{tr}(\rho_{2}F)
\quad \forall F=F^{\dagger}.
$$

> 💡 **Recall (Quantum Foundations):** Your QF notes treated Hermitian operators as a real Hilbert space with the Hilbert-Schmidt inner product. That is the hidden reason why equality of all expectation values forces $\rho_{1}=\rho_{2}$.

**Fact (Convexity).** If $\rho_{1},\dots,\rho_{n}\in\mathcal{D}(\mathcal{H})$ and $p_{1},\dots,p_{n}\geq 0$ with $\sum_{k} p_{k}=1$, then

$$
\rho = \sum_{k=1}^{n} p_{k}\rho_{k}
$$

also lies in $\mathcal{D}(\mathcal{H})$.

### 3.4 Pure versus mixed states

**Theorem.** A density matrix $\rho$ is pure if and only if

$$
\operatorname{tr}(\rho^{2}) = 1.
$$

Equivalently, since $\operatorname{tr}(\rho)=1$ for every state,

$$
\rho \text{ is pure }
\iff
\operatorname{tr}(\rho^{2})=\operatorname{tr}(\rho).
$$

**Proof.**

- If $\rho=|\psi\rangle\langle\psi|$, then $\rho^{2}=\rho$, hence $\operatorname{tr}(\rho^{2})=1$.

- Conversely, let

$$
\rho = \sum_{k}\lambda_{k}|e_{k}\rangle\langle e_{k}|.
$$

Then

$$
\operatorname{tr}(\rho^{2})=\sum_{k}\lambda_{k}^{2}.
$$

If $\operatorname{tr}(\rho^{2})=1=\sum_{k}\lambda_{k}$, then

$$
0
= \sum_{k}\lambda_{k} - \sum_{k}\lambda_{k}^{2}
= \sum_{k}\lambda_{k}(1-\lambda_{k}).
$$

Since each $\lambda_{k}\in [0,1]$, every term is nonnegative, so each term must be $0$. Hence exactly one eigenvalue is $1$ and the rest are $0$, so $\rho$ is rank $1$.

$\square$

**Theorem (Unitary freedom of ensembles).** Let

$$
\rho = \sum_{k=1}^{n}\lambda_{k}|e_{k}\rangle\langle e_{k}|
$$

be the spectral decomposition of $\rho$, with $\lambda_{k}>0$. Then

$$
\rho = \sum_{i=1}^{m} p_{i}|\psi_{i}\rangle\langle\psi_{i}|
$$

if and only if

1. $m\geq n$,
2. there exists a unitary matrix $U\in\mathcal{U}(m)$ such that

$$
\sqrt{p_{i}}|\psi_{i}\rangle
= \sum_{j=1}^{n} U_{ij}\sqrt{\lambda_{j}}|e_{j}\rangle
\qquad
\text{for all } i.
$$

**Remark.** A mixed state has many pure-state decompositions. The spectral decomposition is canonical, but not unique as an ensemble description.

### 3.5 Entropy and time evolution of mixed states

**Definition (von Neumann entropy).**

$$
S(\rho) := -\operatorname{tr}(\rho \log \rho).
$$

If $\rho=\sum_{k}\lambda_{k}|e_{k}\rangle\langle e_{k}|$, then

$$
S(\rho) = -\sum_{k}\lambda_{k}\log \lambda_{k}.
$$

**Remark.**

$$
S(\rho)=0 \iff \rho \text{ is pure}.
$$

For the maximally mixed state $\rho_{*}=\frac{1}{d}I$ on $\mathbb{C}^{d}$,

$$
S(\rho_{*})=\log d.
$$

**Theorem (Unitary evolution of density matrices).** If a closed system evolves by $U(t,t_{0})$, then

$$
\rho(t)=U(t,t_{0})\rho(t_{0})U(t,t_{0})^{\dagger}.
$$

**Proof.** If

$$
\rho(t_{0})=\sum_{k} p_{k}|\psi_{k}(t_{0})\rangle\langle\psi_{k}(t_{0})|,
$$

then each pure state evolves as $|\psi_{k}(t)\rangle=U(t,t_{0})|\psi_{k}(t_{0})\rangle$, so

$$
\rho(t)
= \sum_{k} p_{k} |\psi_{k}(t)\rangle\langle\psi_{k}(t)|
= \sum_{k} p_{k} U|\psi_{k}(t_{0})\rangle\langle\psi_{k}(t_{0})|U^{\dagger}
= U\rho(t_{0})U^{\dagger}.
$$

$\square$

## 4. Systems with Subsystems

### 4.1 Tensor-product structure

**Definition (Composite system).** Let $\mathcal{H}_{1},\dots,\mathcal{H}_{N}$ be Hilbert spaces.

- For distinguishable subsystems,

$$
\mathcal{H} = \mathcal{H}_{1}\otimes \cdots \otimes \mathcal{H}_{N}.
$$

- For indistinguishable particles with one-particle space $\mathbb{C}^{d}$,

$$
\mathcal{H}_{\mathrm{fermionic}} = \bigwedge^{N}\mathbb{C}^{d},
\qquad
\mathcal{H}_{\mathrm{bosonic}} = \bigvee^{N}\mathbb{C}^{d}.
$$

**Remark.** In these notes, the computationally relevant case is the distinguishable tensor-product model.

**Definition (Product and separable pure states).** A bipartite pure state is a product state if it has the form

$$
|\Psi\rangle = |\psi_{1}\rangle \otimes |\psi_{2}\rangle.
$$

Such a state is also called separable or unentangled.

### 4.2 Reduced states for two subsystems

Let

$$
\mathcal{H}_{1}=\operatorname{span}\{|e_{1}\rangle,\dots,|e_{d_{1}}\rangle\},
\qquad
\mathcal{H}_{2}=\operatorname{span}\{|f_{1}\rangle,\dots,|f_{d_{2}}\rangle\},
$$

and let

$$
|\Psi\rangle
= \sum_{i=1}^{d_{1}}\sum_{j=1}^{d_{2}} C_{ij}|e_{i}\rangle\otimes|f_{j}\rangle.
$$

**Definition (Reduced state).** The state of subsystem $1$ is the unique density matrix $\rho^{(1)}$ such that

$$
\operatorname{tr}(\rho^{(1)}F_{1})
= \langle \Psi | (F_{1}\otimes I)|\Psi\rangle
\qquad
\forall F_{1}\in \operatorname{Herm}(\mathcal{H}_{1}).
$$

Similarly, $\rho^{(2)}$ is defined by

$$
\operatorname{tr}(\rho^{(2)}F_{2})
= \langle \Psi | (I\otimes F_{2})|\Psi\rangle
\qquad
\forall F_{2}\in \operatorname{Herm}(\mathcal{H}_{2}).
$$

> 💡 **Recall (Quantum Foundations):** In your QF Schmidt/partial-trace notes, a bipartite pure state was encoded by a coefficient matrix $C$. The reduced states were obtained by summing over the hidden index, producing exactly $CC^{\dagger}$ and $C^{T}\overline{C}$.

**Theorem.** With the above coefficient matrix $C$,

$$
\rho^{(1)} = CC^{\dagger},
\qquad
\rho^{(2)} = C^{T}\overline{C}.
$$

**Proof.** For subsystem $1$,

$$
\begin{aligned}
\langle \Psi | (F_{1}\otimes I)|\Psi\rangle
&=
\sum_{i,k=1}^{d_{1}}\sum_{j=1}^{d_{2}}
\overline{C}_{kj}C_{ij}\langle e_{k}|F_{1}|e_{i}\rangle \\
&=
\sum_{i,k=1}^{d_{1}}
\left(\sum_{j=1}^{d_{2}} C_{ij}\overline{C}_{kj}\right)
\langle e_{k}|F_{1}|e_{i}\rangle.
\end{aligned}
$$

Hence the matrix elements are

$$
\langle e_{i}|\rho^{(1)}|e_{k}\rangle
= \sum_{j=1}^{d_{2}} C_{ij}\overline{C}_{kj}
= (CC^{\dagger})_{ik}.
$$

The second formula is obtained similarly:

$$
\langle f_{j}|\rho^{(2)}|f_{l}\rangle
= \sum_{i=1}^{d_{1}} C_{ij}\overline{C}_{il}
= (C^{T}\overline{C})_{jl}.
$$

$\square$

**Example.** If

$$
|\Psi\rangle = |\psi_{1}\rangle\otimes|\psi_{2}\rangle,
$$

then

$$
\rho^{(1)} = |\psi_{1}\rangle\langle\psi_{1}|,
\qquad
\rho^{(2)} = |\psi_{2}\rangle\langle\psi_{2}|.
$$

### 4.3 Partial trace in general

**Definition (Partial trace).** Let

$$
\mathcal{H}=\mathcal{H}_{1}\otimes\cdots\otimes\mathcal{H}_{N}
$$

and let $\rho$ be a state on $\mathcal{H}$. The reduced state on subsystem $k$ is denoted by

$$
\rho^{(k)}=\operatorname{tr}_{1,\dots,k-1,k+1,\dots,N}(\rho).
$$

In the standard tensor basis,

$$
\langle i_{k}|\rho^{(k)}|j_{k}\rangle
=
\sum_{i_{1},\dots,\widehat{i_{k}},\dots,i_{N}}
\langle i_{1}\cdots i_{k}\cdots i_{N}|\rho|i_{1}\cdots j_{k}\cdots i_{N}\rangle,
$$

where the hat indicates that the $k$-th index is omitted from the summation.

**Remark.** The reduced state is characterized by the identity

$$
\operatorname{tr}(\rho^{(k)}F_{k})
= \operatorname{tr}(\rho \widetilde{F}_{k}),
$$

where

$$
\widetilde{F}_{k}
= I\otimes\cdots\otimes I \otimes F_{k}\otimes I\otimes\cdots\otimes I.
$$

That is, the reduced state is precisely the object that reproduces all local expectation values.

## 5. Schmidt Form and Entanglement

### 5.1 Linear algebra behind the Schmidt decomposition

**Lemma.** For any linear operator $F$,

1. $\ker(F)=\ker(F^{\dagger}F)$ and $\ker(F^{\dagger})=\ker(FF^{\dagger})$,
2. $FF^{\dagger}$ and $F^{\dagger}F$ have the same nonzero eigenvalues with the same multiplicities.

**Proof.** If $F^{\dagger}Fv=0$, then

$$
0=\langle v|F^{\dagger}F|v\rangle=\|Fv\|^{2},
$$

so $Fv=0$. This gives $\ker(F^{\dagger}F)=\ker(F)$, and the other kernel identity is identical.

If $F^{\dagger}Fv=\lambda v$ with $\lambda\neq 0$, then

$$
FF^{\dagger}(Fv)=\lambda(Fv),
$$

and $Fv\neq 0$. Hence every nonzero eigenvalue of $F^{\dagger}F$ is also an eigenvalue of $FF^{\dagger}$, and conversely by symmetry.

$\square$

### 5.2 Local unitary action

**Theorem.** Let $|\widetilde{\Psi}\rangle=(U\otimes V)|\Psi\rangle$, where $U$ and $V$ are unitary. If $\rho_{1}$ and $\rho_{2}$ are the reduced states of $|\Psi\rangle$, then the reduced states of $|\widetilde{\Psi}\rangle$ are

$$
\widetilde{\rho}_{1}=U\rho_{1}U^{\dagger},
\qquad
\widetilde{\rho}_{2}=V\rho_{2}V^{\dagger}.
$$

**Proof.** For every observable $F_{1}$ on subsystem $1$,

$$
\begin{aligned}
\operatorname{tr}(\widetilde{\rho}_{1}F_{1})
&=
\langle \widetilde{\Psi}|F_{1}\otimes I|\widetilde{\Psi}\rangle \\
&=
\langle \Psi|U^{\dagger}F_{1}U \otimes I|\Psi\rangle \\
&=
\operatorname{tr}(\rho_{1}U^{\dagger}F_{1}U)
=
\operatorname{tr}(U\rho_{1}U^{\dagger}F_{1}).
\end{aligned}
$$

By uniqueness of the reduced state, $\widetilde{\rho}_{1}=U\rho_{1}U^{\dagger}$. The second formula is identical.

$\square$

**Remark.** Local unitaries change local bases, but they do not change the entanglement content.

### 5.3 Schmidt decomposition

**Theorem (Schmidt decomposition).** Let $|\Psi\rangle \in \mathcal{H}_{1}\otimes\mathcal{H}_{2}$ be a normalized bipartite pure state. Then there exist orthonormal families $\{|u_{i}\rangle\}$ in $\mathcal{H}_{1}$ and $\{|v_{i}\rangle\}$ in $\mathcal{H}_{2}$, together with numbers $p_{i}\geq 0$ satisfying $\sum_{i} p_{i}=1$, such that

$$
|\Psi\rangle = \sum_{i=1}^{r}\sqrt{p_{i}}\,|u_{i}\rangle\otimes|v_{i}\rangle,
$$

where $r\leq \min\{\dim\mathcal{H}_{1},\dim\mathcal{H}_{2}\}$.

**Proof.** Write $|\Psi\rangle$ using a coefficient matrix $C$. By singular value decomposition,

$$
C = UDV^{T},
$$

where $D$ is diagonal with nonnegative diagonal entries. Absorbing $U$ and $V$ into new orthonormal bases gives

$$
|\Psi\rangle = \sum_{i}\lambda_{i}|u_{i}\rangle\otimes|v_{i}\rangle.
$$

Normalization gives $\sum_{i}\lambda_{i}^{2}=1$. Setting $p_{i}:=\lambda_{i}^{2}$ completes the proof.

$\square$

**Corollary.** If

$$
|\Psi\rangle = \sum_{i=1}^{r}\sqrt{p_{i}}\,|u_{i}\rangle\otimes|v_{i}\rangle,
$$

then

$$
\rho_{1} = \sum_{i=1}^{r} p_{i}|u_{i}\rangle\langle u_{i}|,
\qquad
\rho_{2} = \sum_{i=1}^{r} p_{i}|v_{i}\rangle\langle v_{i}|.
$$

In particular, the two reduced density matrices have the same nonzero spectrum.

### 5.4 Entanglement

**Definition (Entangled pure state).** A bipartite pure state is entangled if it is not a product state.

**Criterion.** A bipartite pure state is separable if and only if it has exactly one nonzero Schmidt coefficient.

**Definition (Entropy of entanglement).** For a pure bipartite state $|\Psi\rangle$, define

$$
S_{E}(|\Psi\rangle) := S(\rho_{1}) = S(\rho_{2}),
$$

where $\rho_{1}$ and $\rho_{2}$ are the reduced states.

If the Schmidt coefficients are $\{p_{i}\}$, then

$$
S_{E}(|\Psi\rangle) = -\sum_{i} p_{i}\log p_{i}.
$$

**Remark.**

- $S_{E}(|\Psi\rangle)=0$ exactly for separable pure states.
- The maximal value is $\log d$ for a maximally entangled state in $\mathbb{C}^{d}\otimes\mathbb{C}^{d}$.

**Example (Maximally entangled state).**

$$
|\Psi_{\max}\rangle
= \frac{1}{\sqrt{d}}\sum_{i=0}^{d-1}|i\rangle\otimes|i\rangle.
$$

Its reduced states are both $\frac{1}{d}I$, so

$$
S_{E}(|\Psi_{\max}\rangle)=\log d.
$$

### 5.5 Creating a mixed state by forgetting a measurement outcome

**Proposition.** Let $F=\sum_{\lambda}\lambda P_{\lambda}$ be an observable and suppose the initial state is the pure state $|\psi\rangle$. If the measurement is performed but the result is not recorded, the resulting state is

$$
\rho_{\mathrm{after}}
= \sum_{\lambda} P_{\lambda}|\psi\rangle\langle\psi|P_{\lambda}.
$$

**Remark.** This is exactly how classical ignorance turns a pure state into a mixed state.

### 5.6 Partial trace identities and local measurements

**Lemma.** For simple tensors on $\mathcal{H}_{1}\otimes\mathcal{H}_{2}$,

$$
\operatorname{tr}_{1}(A\otimes B)=\operatorname{tr}(A)\,B.
$$

**Proof.** In an orthonormal basis $\{|i\rangle\}$ of $\mathcal{H}_{1}$,

$$
\begin{aligned}
\operatorname{tr}_{1}(A\otimes B)
&=
\sum_{i} (\langle i|\otimes I)(A\otimes B)(|i\rangle\otimes I) \\
&=
\sum_{i}\langle i|A|i\rangle\,B \\
&=
\operatorname{tr}(A)\,B.
\end{aligned}
$$

$\square$

**Lemma (Cyclicity in the traced subsystem).** If $X$ acts only on subsystem $1$, then

$$
\operatorname{tr}_{1}[(X\otimes I)Y]
=
\operatorname{tr}_{1}[Y(X\otimes I)].
$$

**Remark.** This is the partial-trace version of the cyclicity of the ordinary trace, but only for factors that live inside the subsystem being traced out.

**Theorem (No change on the unmeasured subsystem when the outcome is unknown).** Let $\rho$ be a state on $\mathcal{H}_{A}\otimes\mathcal{H}_{B}$. Suppose a projective measurement $\{P_{\lambda}\}$ is performed on subsystem $A$, but the outcome is not revealed. Then the post-measurement reduced state on subsystem $B$ is still

$$
\rho_{B}=\operatorname{tr}_{A}(\rho).
$$

**Proof.** The average post-measurement state is

$$
\rho'=\sum_{\lambda}(P_{\lambda}\otimes I)\rho(P_{\lambda}\otimes I).
$$

Therefore

$$
\begin{aligned}
\rho'_{B}
&=
\operatorname{tr}_{A}(\rho') \\
&=
\sum_{\lambda}\operatorname{tr}_{A}\left((P_{\lambda}\otimes I)\rho(P_{\lambda}\otimes I)\right) \\
&=
\sum_{\lambda}\operatorname{tr}_{A}\left((P_{\lambda}^{2}\otimes I)\rho\right) \\
&=
\operatorname{tr}_{A}\left(\left(\sum_{\lambda}P_{\lambda}\otimes I\right)\rho\right) \\
&=
\operatorname{tr}_{A}(\rho)
= \rho_{B}.
\end{aligned}
$$

$\square$

**Remark.** This is the structural reason behind the no-communication theorem.

## 6. Matrix Lie Groups and Lie Algebras

### 6.1 Matrix Lie groups

**Definition (Matrix Lie group).** Let $\mathbb{K}=\mathbb{R}$ or $\mathbb{C}$. A matrix Lie group is a subset $G\subseteq GL(n,\mathbb{K})$ such that

1. $AB\in G$ whenever $A,B\in G$,
2. $A^{-1}\in G$ whenever $A\in G$,
3. $I\in G$,
4. $G$ is closed in $GL(n,\mathbb{K})$.

**Examples.**

$$
SL(n,\mathbb{K}),\quad U(n),\quad SU(n),\quad O(n),\quad SO(n)
$$

are all matrix Lie groups.

**Definition (Lie group homomorphism).** If $G$ and $H$ are matrix Lie groups, a map $\Phi:G\to H$ is a Lie group homomorphism if

1. $\Phi(g_{1}g_{2})=\Phi(g_{1})\Phi(g_{2})$,
2. $\Phi(I)=I$,
3. $\Phi$ is continuous.

If moreover $\Phi$ is bijective and $\Phi^{-1}$ is continuous, then $\Phi$ is a Lie group isomorphism.

**Example.** The map

$$
\Phi:\mathbb{R}\to SO(2),
\qquad
\Phi(\theta)=
\begin{pmatrix}
\cos\theta & -\sin\theta \\
\sin\theta & \cos\theta
\end{pmatrix},
$$

is a Lie group homomorphism.

### 6.2 Lie product formula

**Theorem (Lie product formula).** For $X,Y\in M_{n}(\mathbb{C})$,

$$
e^{X+Y}
=
\lim_{m\to\infty}\left(e^{X/m}e^{Y/m}\right)^{m}.
$$

**Remark.** This is the basic tool that allows addition in the Lie algebra to be related to multiplication in the Lie group.

### 6.3 Lie algebras

**Definition (Lie algebra).** A finite-dimensional real or complex Lie algebra is a vector space $\mathfrak{g}$ together with a bilinear map

$$
[\cdot,\cdot]:\mathfrak{g}\times\mathfrak{g}\to\mathfrak{g}
$$

such that

1. $[X,Y]=-[Y,X]$,
2. $[X,[Y,Z]]+[Y,[Z,X]]+[Z,[X,Y]]=0$.

**Remark.** If $[X,Y]=0$, we say that $X$ and $Y$ commute.

**Examples.**

1. $\mathbb{R}^{3}$ with the cross product,
2. $M_{n}(\mathbb{K})$ with the commutator

$$
[A,B]=AB-BA.
$$

**Definition (Lie algebra homomorphism).** A linear map $\varphi:\mathfrak{g}\to\mathfrak{h}$ is a Lie algebra homomorphism if

$$
\varphi([X,Y]_{\mathfrak{g}})=[\varphi(X),\varphi(Y)]_{\mathfrak{h}}.
$$

### 6.4 The Lie algebra of a matrix Lie group

**Definition.** If $G\subseteq GL(n,\mathbb{C})$ is a matrix Lie group, define

$$
\operatorname{Lie}(G)
:=
\{X\in M_{n}(\mathbb{C}) : e^{tX}\in G \text{ for all } t\in\mathbb{R}\}.
$$

**Theorem.** If $\mathfrak{g}=\operatorname{Lie}(G)$, then

1. $gXg^{-1}\in\mathfrak{g}$ for all $g\in G$, $X\in\mathfrak{g}$,
2. $\alpha X\in\mathfrak{g}$ for all $\alpha\in\mathbb{R}$, $X\in\mathfrak{g}$,
3. $X+Y\in\mathfrak{g}$ for all $X,Y\in\mathfrak{g}$,
4. $[X,Y]\in\mathfrak{g}$ for all $X,Y\in\mathfrak{g}$.

**Remark.** The first statement says the Lie algebra is stable under conjugation, and the fourth is the source of the Lie bracket.

**Examples.**

$$
\operatorname{Lie}(GL(n,\mathbb{K}))=\mathfrak{gl}(n,\mathbb{K})=M_{n}(\mathbb{K}),
$$

$$
\operatorname{Lie}(SL(n,\mathbb{K}))=\mathfrak{sl}(n,\mathbb{K})
=
\{X:\operatorname{tr}(X)=0\},
$$

$$
\operatorname{Lie}(U(n))=\mathfrak{u}(n)
=
\{X\in M_{n}(\mathbb{C}) : X^{\dagger}=-X\},
$$

$$
\operatorname{Lie}(SU(n))=\mathfrak{su}(n)
=
\{X\in M_{n}(\mathbb{C}) : X^{\dagger}=-X,\ \operatorname{tr}(X)=0\},
$$

$$
\operatorname{Lie}(O(n))=\mathfrak{o}(n)
=
\{X\in M_{n}(\mathbb{R}) : X^{T}=-X\},
$$

$$
\operatorname{Lie}(SO(n))=\mathfrak{so}(n)
=
\{X\in M_{n}(\mathbb{R}) : X^{T}=-X\}.
$$

### 6.5 One-parameter subgroups and differentiation

**Definition (One-parameter subgroup).** A one-parameter subgroup of $GL(n,\mathbb{C})$ is a continuous map

$$
g:\mathbb{R}\to GL(n,\mathbb{C})
$$

satisfying

$$
g(0)=I,
\qquad
g(t+s)=g(t)g(s).
$$

**Theorem.** If $g(t)$ is a one-parameter subgroup of a matrix Lie group $G$, then there exists a unique $X\in \operatorname{Lie}(G)$ such that

$$
g(t)=e^{tX}
\qquad
\forall t\in\mathbb{R}.
$$

**Theorem (Differential of a Lie group homomorphism).** Let $\Phi:G\to H$ be a Lie group homomorphism, and let

$$
\mathfrak{g}=\operatorname{Lie}(G),
\qquad
\mathfrak{h}=\operatorname{Lie}(H).
$$

Then there exists a unique real-linear map $\varphi:\mathfrak{g}\to\mathfrak{h}$ such that

$$
\Phi(e^{X})=e^{\varphi(X)}.
$$

Moreover,

1.

$$
\varphi(X)=\left.\frac{d}{dt}\right|_{t=0}\Phi(e^{tX}),
$$

2.

$$
\varphi(gXg^{-1})=\Phi(g)\varphi(X)\Phi(g)^{-1},
$$

3.

$$
\varphi([X,Y])=[\varphi(X),\varphi(Y)].
$$

**Remark.** Every Lie group homomorphism induces a Lie algebra homomorphism.

## 7. The Adjoint Representation

### 7.1 Big adjoint and little adjoint

**Definition (Adjoint map).** For $g\in G$, define

$$
\operatorname{Ad}_{g}:\mathfrak{g}\to\mathfrak{g},
\qquad
\operatorname{Ad}_{g}(X)=gXg^{-1}.
$$

**Lemma.** For each $g\in G$, the map $\operatorname{Ad}_{g}$ is a linear isomorphism.

**Proof.** Linearity is immediate:

$$
\operatorname{Ad}_{g}(X+Y)=g(X+Y)g^{-1}=gXg^{-1}+gYg^{-1},
$$

and similarly for scalars. The inverse is $\operatorname{Ad}_{g^{-1}}$.

$\square$

**Theorem (Adjoint representation).** The map

$$
\operatorname{Ad}:G\to GL(\mathfrak{g}),
\qquad
g\mapsto \operatorname{Ad}_{g},
$$

is a Lie group homomorphism.

**Definition (Infinitesimal adjoint action).** The induced Lie algebra homomorphism is denoted by

$$
\operatorname{ad}:\mathfrak{g}\to \mathfrak{gl}(\mathfrak{g}).
$$

For $X\in\mathfrak{g}$,

$$
\operatorname{ad}_{X}(Y)
:=
\left.\frac{d}{dt}\right|_{t=0}\operatorname{Ad}_{e^{tX}}(Y).
$$

**Lemma.**

$$
\operatorname{ad}_{X}(Y)=[X,Y].
$$

**Proof.**

$$
\operatorname{ad}_{X}(Y)
=
\left.\frac{d}{dt}\right|_{t=0} e^{tX}Ye^{-tX}
= XY-YX.
$$

$\square$

**Corollary.**

$$
\operatorname{Ad}_{e^{X}} = e^{\operatorname{ad}_{X}}.
$$

Equivalently,

$$
e^{X}Ye^{-X}
=
Y+[X,Y]+\frac{1}{2!}[X,[X,Y]]+\cdots.
$$

## 8. The Adjoint Representation of $SU(d)$

### 8.1 Geometry on $\mathfrak{su}(d)$

**Definition (Hilbert-Schmidt inner product on $\mathfrak{su}(d)$).** For $X,Y\in\mathfrak{su}(d)$, define

$$
(X|Y)_{HS}
:=
d\,\operatorname{tr}(X^{\dagger}Y)
=
-d\,\operatorname{tr}(XY).
$$

**Remark.** Since $X^{\dagger}=-X$ on $\mathfrak{su}(d)$, the two formulas agree.

**Theorem.** For every $U\in SU(d)$, the adjoint action

$$
\operatorname{Ad}_{U}(X)=UXU^{-1}
$$

preserves the Hilbert-Schmidt inner product. Hence

$$
\operatorname{Ad}_{U}\in SO(\mathfrak{su}(d))\cong SO(d^{2}-1).
$$

**Proof.**

$$
\begin{aligned}
(\operatorname{Ad}_{U}(X)|\operatorname{Ad}_{U}(Y))_{HS}
&=
-d\,\operatorname{tr}(UXU^{-1}UYU^{-1}) \\
&=
-d\,\operatorname{tr}(UXYU^{-1}) \\
&=
-d\,\operatorname{tr}(XY) \\
&=
(X|Y)_{HS}.
\end{aligned}
$$

$\square$

### 8.2 Matrix elements of the adjoint action

**Definition.** Let $\{\gamma_{1},\dots,\gamma_{d^{2}-1}\}$ be an orthonormal basis of $\mathfrak{su}(d)$ with respect to $(\cdot|\cdot)_{HS}$. The matrix coefficients of $\operatorname{Ad}_{U}$ in this basis are

$$
[\operatorname{Ad}_{U}]_{ij}
=
(\gamma_{i}|\operatorname{Ad}_{U}(\gamma_{j}))_{HS}
=
-d\,\operatorname{tr}(\gamma_{i}U\gamma_{j}U^{-1}).
$$

**Remark.** This identifies the adjoint action with an ordinary real orthogonal matrix of size $(d^{2}-1)\times(d^{2}-1)$.

## 9. The Special Case $SU(2)$ and the Pauli Matrices

### 9.1 Pauli matrices

**Definition (Pauli matrices).**

$$
\sigma_{x}=
\begin{pmatrix}
0 & 1 \\
1 & 0
\end{pmatrix},
\qquad
\sigma_{y}=
\begin{pmatrix}
0 & -i \\
i & 0
\end{pmatrix},
\qquad
\sigma_{z}=
\begin{pmatrix}
1 & 0 \\
0 & -1
\end{pmatrix},
\qquad
I=
\begin{pmatrix}
1 & 0 \\
0 & 1
\end{pmatrix}.
$$

Let $\epsilon_{jkl}$ be the Levi-Civita symbol.

> 💡 **Recall (Quantum Foundations):** In your QF notes, $\{I,\sigma_{x},\sigma_{y},\sigma_{z}\}$ already appeared as a real basis of $\operatorname{Herm}(\mathbb{C}^{2})$. That is exactly why they reappear here as the natural coordinates for qubit states and qubit observables.

**Lemma (Pauli algebra).** For $j,k\in\{1,2,3\}$,

$$
\sigma_{j}\sigma_{k}
=
\delta_{jk}I
+
i\sum_{l=1}^{3}\epsilon_{jkl}\sigma_{l}.
$$

Consequently,

$$
[\sigma_{j},\sigma_{k}]
=
2i\sum_{l=1}^{3}\epsilon_{jkl}\sigma_{l},
$$

and

$$
\{\sigma_{j},\sigma_{k}\}
=
2\delta_{jk}I.
$$

**Remark.** Each Pauli matrix is both Hermitian and unitary:

$$
\sigma_{j}^{\dagger}=\sigma_{j},
\qquad
\sigma_{j}^{2}=I.
$$

### 9.2 The Lie algebra $\mathfrak{su}(2)$

**Definition.** Set

$$
\widetilde{\sigma}_{k}:=-\frac{i}{2}\sigma_{k},
\qquad
k=1,2,3.
$$

Then $\widetilde{\sigma}_{k}\in \mathfrak{su}(2)$.

**Lemma.**

$$
[\widetilde{\sigma}_{j},\widetilde{\sigma}_{k}]
=
\sum_{l=1}^{3}\epsilon_{jkl}\widetilde{\sigma}_{l}.
$$

**Corollary.**

$$
\mathfrak{su}(2)
=
\operatorname{span}_{\mathbb{R}}\{\widetilde{\sigma}_{1},\widetilde{\sigma}_{2},\widetilde{\sigma}_{3}\}.
$$

### 9.3 Isomorphism with $\mathbb{R}^{3}$

**Definition.** For $\vec{a}=(a_{1},a_{2},a_{3})\in\mathbb{R}^{3}$, write

$$
\vec{a}\cdot\widetilde{\vec{\sigma}}
:=
a_{1}\widetilde{\sigma}_{1}+a_{2}\widetilde{\sigma}_{2}+a_{3}\widetilde{\sigma}_{3}.
$$

**Theorem.** The map

$$
\mathbb{R}^{3}\to \mathfrak{su}(2),
\qquad
\vec{a}\mapsto \vec{a}\cdot\widetilde{\vec{\sigma}},
$$

is a Lie algebra isomorphism. More precisely,

1.

$$
(\vec{a}\cdot\widetilde{\vec{\sigma}} \mid \vec{b}\cdot\widetilde{\vec{\sigma}})_{HS}
=
\vec{a}\cdot\vec{b},
$$

2.

$$
[\vec{a}\cdot\widetilde{\vec{\sigma}},\vec{b}\cdot\widetilde{\vec{\sigma}}]
=
(\vec{a}\times\vec{b})\cdot\widetilde{\vec{\sigma}}.
$$

**Remark.** This is the structural reason that qubits can be visualized geometrically by ordinary three-dimensional rotations.

### 9.4 Exponentiation and the map $SU(2)\to SO(3)$

**Lemma.** If $\hat{n}\in\mathbb{R}^{3}$ is a unit vector, then

$$
(\hat{n}\cdot\vec{\sigma})^{2}=I.
$$

Hence

$$
e^{-i\frac{\alpha}{2}\hat{n}\cdot\vec{\sigma}}
=
\cos\left(\frac{\alpha}{2}\right)I
- i\sin\left(\frac{\alpha}{2}\right)\hat{n}\cdot\vec{\sigma}.
$$

**Theorem.** Every element of $SU(2)$ can be written as

$$
U=e^{\alpha \hat{n}\cdot\widetilde{\vec{\sigma}}}
=
e^{-i\frac{\alpha}{2}\hat{n}\cdot\vec{\sigma}}
$$

for some unit vector $\hat{n}$ and real parameter $\alpha$. Under the adjoint representation, this induces a rotation in $SO(3)$ about the axis $\hat{n}$ by angle $\alpha$.

**Remark.** The map

$$
\operatorname{Ad}:SU(2)\to SO(3)
$$

is surjective and $2$-to-$1$: both $U$ and $-U$ produce the same spatial rotation.

## 10. Qubits and the Bloch Sphere

### 10.1 Qubits

**Definition (Qubit).** A qubit is a quantum system with Hilbert space $\mathbb{C}^{2}$.

We choose the computational basis

$$
\{|0\rangle,|1\rangle\},
$$

usually taken to be the eigenbasis of $\sigma_{z}$:

$$
\sigma_{z}|0\rangle=|0\rangle,
\qquad
\sigma_{z}|1\rangle=-|1\rangle.
$$

### 10.2 Bloch-vector parametrization

**Theorem (Bloch form of a qubit state).** Every qubit density matrix can be written uniquely as

$$
\rho_{\vec{x}}
=
\frac{1}{2}\left(I+\vec{x}\cdot\vec{\sigma}\right),
\qquad
\vec{x}\in\mathbb{R}^{3},
$$

with the constraint

$$
|\vec{x}|\leq 1.
$$

**Proof.** Since $\{I,\sigma_{x},\sigma_{y},\sigma_{z}\}$ is a real basis of $\operatorname{Herm}(\mathbb{C}^{2})$, every Hermitian $2\times 2$ matrix has the form

$$
a_{0}I+\vec{a}\cdot\vec{\sigma}.
$$

The trace condition $\operatorname{tr}(\rho)=1$ forces $a_{0}=\frac{1}{2}$. Writing $\vec{x}=2\vec{a}$ gives

$$
\rho_{\vec{x}}=\frac{1}{2}(I+\vec{x}\cdot\vec{\sigma}).
$$

Now use

$$
(\vec{x}\cdot\vec{\sigma})^{2}=|\vec{x}|^{2}I
$$

to compute the eigenvalues of $\rho_{\vec{x}}$:

$$
q_{\pm}=\frac{1}{2}(1\pm |\vec{x}|).
$$

Positivity is therefore equivalent to $q_{\pm}\geq 0$, which is equivalent to $|\vec{x}|\leq 1$.

$\square$

**Corollary.** The qubit state $\rho_{\vec{x}}$ is pure if and only if $|\vec{x}|=1$.

**Proof.** We have

$$
\rho_{\vec{x}}^{2}
=
\frac{1}{4}(I+2\vec{x}\cdot\vec{\sigma}+|\vec{x}|^{2}I).
$$

Thus $\rho_{\vec{x}}^{2}=\rho_{\vec{x}}$ exactly when $|\vec{x}|^{2}=1$.

$\square$

**Remark (Bloch sphere).**

- $|\vec{x}|=1$ corresponds to pure states,
- $|\vec{x}|<1$ corresponds to mixed states,
- $\vec{x}=0$ corresponds to the maximally mixed state $\frac{1}{2}I$.

![Bloch sphere](assets/ocr-20260421194049-9erjdxd.png)

## 11. Operations on Qubits

### 11.1 The decomposition of a $2\times 2$ unitary

**Theorem.** Every $W\in U(2)$ can be written as

$$
W=e^{i\phi}U
$$

with $U\in SU(2)$.

**Proof.** Let $\det(W)=e^{i\theta}$. Choose $\phi=\theta/2$. Then

$$
U:=e^{-i\phi}W
$$

satisfies

$$
\det(U)=e^{-2i\phi}\det(W)=1.
$$

Hence $U\in SU(2)$ and $W=e^{i\phi}U$.

$\square$

**Remark (Global phase disappears).** For every density matrix $\rho$,

$$
(e^{i\phi}U)\rho(e^{i\phi}U)^{\dagger}
=
U\rho U^{\dagger}.
$$

So only the $SU(2)$ part matters physically.

### 11.2 Action on the Bloch sphere

**Theorem.** Let

$$
\rho_{\vec{x}}=\frac{1}{2}(I+\vec{x}\cdot\vec{\sigma}),
\qquad
U\in SU(2).
$$

Then there exists a rotation $R_{U}\in SO(3)$ such that

$$
U\rho_{\vec{x}}U^{\dagger}
=
\frac{1}{2}\left(I+(R_{U}\vec{x})\cdot\vec{\sigma}\right).
$$

**Proof.** Conjugation preserves the identity and acts linearly on the span of the Pauli matrices:

$$
U\rho_{\vec{x}}U^{\dagger}
=
\frac{1}{2}I+\frac{1}{2}U(\vec{x}\cdot\vec{\sigma})U^{\dagger}.
$$

But the adjoint action of $SU(2)$ on the traceless Hermitian matrices is exactly the $SO(3)$ rotation action induced by the Lie algebra isomorphism from the previous section. Hence

$$
U(\vec{x}\cdot\vec{\sigma})U^{\dagger}
=
(R_{U}\vec{x})\cdot\vec{\sigma}.
$$

$\square$

**Remark.** Unitary evolution of a qubit is therefore a rigid rotation of the Bloch vector.

## 12. Generalization to Qudits

### 12.1 Generalized Bloch representation

**Definition.** Let $\mathcal{H}=\mathbb{C}^{d}$ and let

$$
\{\gamma_{1},\dots,\gamma_{d^{2}-1}\}
$$

be an orthonormal basis of $\mathfrak{su}(d)$ with respect to the Hilbert-Schmidt inner product.

Then every trace-$1$ Hermitian operator can be written as

$$
\rho
=
\frac{1}{d}\left(I+i\sum_{k=1}^{d^{2}-1}x_{k}\gamma_{k}\right)
=
\frac{1}{d}\left(I+i\,\vec{x}\cdot\vec{\gamma}\right),
$$

where $\vec{x}\in\mathbb{R}^{d^{2}-1}$.

**Remark.** For $d=2$, positivity is equivalent to $|\vec{x}|\leq 1$. For $d>2$, positivity is more subtle: not every vector in $\mathbb{R}^{d^{2}-1}$ gives a physical state.

### 12.2 Unitary action on qudits

**Theorem.** Let

$$
\rho
=
\frac{1}{d}(I+i\,\vec{x}\cdot\vec{\gamma}),
\qquad
U\in SU(d).
$$

Then

$$
U\rho U^{\dagger}
=
\frac{1}{d}\left(I+i\,(\operatorname{Ad}_{U}\vec{x})\cdot\vec{\gamma}\right),
$$

where $\operatorname{Ad}_{U}$ is the orthogonal transformation induced by the adjoint action of $U$ on $\mathfrak{su}(d)$.

**Proof.** Since $UIU^{\dagger}=I$,

$$
U\rho U^{\dagger}
=
\frac{1}{d}I+\frac{i}{d}U(\vec{x}\cdot\vec{\gamma})U^{\dagger}.
$$

The traceless part lies in $\mathfrak{su}(d)$, and the adjoint action sends it to another element of $\mathfrak{su}(d)$ with coordinates transformed by the orthogonal matrix $[\operatorname{Ad}_{U}]$.

$\square$

**Remark.** The qubit Bloch sphere is the most special case of this construction. For general qudits, one still has a generalized Bloch vector, but the geometry of the physical state space is no longer an ordinary Euclidean ball.
