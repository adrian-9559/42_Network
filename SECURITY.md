# 🛡️ Security Policy / Política de Seguridad

Welcome to our project's comprehensive security policy. The safety, privacy, and protection of our users, contributors, and assets are our highest priorities. This document outlines supported versions, a strict vulnerability reporting process, mandatory restrictions, and advanced best practices for secure contribution. Please read carefully and adhere to all requirements.

Bienvenido a la política de seguridad integral de nuestro proyecto. La seguridad, privacidad y protección de nuestros usuarios, colaboradores y activos son nuestra máxima prioridad. Este documento detalla las versiones soportadas, un proceso estricto de reporte de vulnerabilidades, restricciones obligatorias y buenas prácticas avanzadas para contribuir de forma segura. Por favor, lee atentamente y cumple todos los requisitos.

---

## ✅ Supported Versions / Versiones Soportadas

We strictly maintain only the latest stable and long-term support (LTS) versions. All other versions are considered deprecated and must not be used in production or development environments. Using unsupported versions is strictly prohibited and may result in denial of support or access.

Mantenemos estrictamente solo las versiones estables y de soporte a largo plazo (LTS) más recientes. Todas las demás versiones se consideran obsoletas y no deben utilizarse en entornos de producción ni desarrollo. El uso de versiones no soportadas está estrictamente prohibido y puede resultar en la denegación de soporte o acceso.

| Version | Status                  | Versión | Estado                  |
| ------- | ----------------------- | ------- | ----------------------- |
| 5.1.x   | ✅ Active Support (LTS)  | 5.1.x   | ✅ Soporte Activo (LTS)  |
| 5.0.x   | ❌ Support Ended         | 5.0.x   | ❌ Soporte Finalizado    |
| 4.0.x   | ✅ Active Support        | 4.0.x   | ✅ Soporte Activo        |
| < 4.0   | ❌ Support Ended         | < 4.0   | ❌ Soporte Finalizado    |

**Strict Restrictions / Restricciones Estrictas:**
- Only "Active Support" and "LTS" versions receive security patches and reviews.
- Deprecated versions are not permitted for any official use.
- All environments must be updated to the latest supported version before reporting or investigating vulnerabilities.
- Failure to comply may result in exclusion from the project and revocation of contributor status.

- Solo las versiones marcadas como "Soporte Activo" y "LTS" reciben parches y revisiones de seguridad.
- Las versiones obsoletas no están permitidas para ningún uso oficial.
- Todos los entornos deben actualizarse a la última versión soportada antes de reportar o investigar vulnerabilidades.
- El incumplimiento puede resultar en la exclusión del proyecto y la revocación del estatus de colaborador.

---

## 🐛 Vulnerability Reporting / Reporte de Vulnerabilidades

We enforce a rigorous vulnerability reporting process to ensure the highest level of security. All reports must follow the steps below. Failure to comply may result in delayed or rejected reports.

Aplicamos un proceso riguroso de reporte de vulnerabilidades para garantizar el máximo nivel de seguridad. Todos los reportes deben seguir los pasos indicados. El incumplimiento puede resultar en retrasos o rechazo del reporte.

### 1. 📧 Secure Contact / Contacto Seguro

All vulnerability reports must be sent exclusively via email to [adrian.escribano3@gmail.com](mailto:adrian.escribano3@gmail.com?subject=Security%20Vulnerability%20Report%2042-Madrid%20Repository). Reports sent through other channels will be ignored.

Todos los reportes de vulnerabilidades deben enviarse exclusivamente por correo electrónico a [adrian.escribano3@gmail.com](mailto:adrian.escribano3@gmail.com?subject=Security%20Vulnerability%20Report%2042-Madrid%20Repository). Los reportes enviados por otros canales serán ignorados.

### 2. 📝 Detailed Information / Información Detallada

Your report must include:
- A precise and exhaustive description of the vulnerability.
- Step-by-step instructions to reproduce the issue.
- Assessment of potential impact, exploitation scenarios, and risk level.
- List of affected versions and detailed test environment specifications.
- Supporting evidence (logs, screenshots, PoC, code snippets).
- Disclosure of any prior or parallel reports to other parties.

Tu reporte debe incluir:
- Descripción precisa y exhaustiva de la vulnerabilidad.
- Instrucciones paso a paso para reproducir el problema.
- Evaluación del impacto potencial, escenarios de explotación y nivel de riesgo.
- Lista de versiones afectadas y especificaciones detalladas del entorno de pruebas.
- Evidencia de soporte (logs, capturas, PoC, fragmentos de código).
- Divulgación de cualquier reporte previo o paralelo a otras partes.

### 3. ⏱️ Response Times / Tiempos de Respuesta

- Initial acknowledgment within **48 hours**.
- Status updates at least every **72 hours** during investigation.
- Final notification upon resolution and patch release.
- Reports lacking required information may be delayed or rejected.

- Acuse de recibo inicial en **48 horas**.
- Actualizaciones de estado al menos cada **72 horas** durante la investigación.
- Notificación final tras la resolución y publicación del parche.
- Los reportes sin la información requerida pueden retrasarse o rechazarse.

### 4. 🔧 Resolution and Recognition / Resolución y Reconocimiento

- Confirmed vulnerabilities will be resolved with priority and urgency.
- The reporter will be publicly credited unless anonymity is requested.
- In critical cases, coordinated responsible disclosure will be enforced to minimize user risk.
- All communications regarding vulnerabilities are strictly confidential until public disclosure is authorized.

- Las vulnerabilidades confirmadas se resolverán con prioridad y urgencia.
- El reportero será reconocido públicamente salvo que solicite anonimato.
- En casos críticos, se aplicará divulgación responsable coordinada para minimizar riesgos a usuarios.
- Todas las comunicaciones sobre vulnerabilidades son estrictamente confidenciales hasta que se autorice la divulgación pública.

---

## 🚫 Mandatory Restrictions and Advanced Best Practices / Restricciones Obligatorias y Buenas Prácticas Avanzadas

To safeguard the project, the following restrictions are mandatory. Violations will result in immediate removal from the project and may be reported to relevant authorities.

Para proteger el proyecto, las siguientes restricciones son obligatorias. Las infracciones resultarán en la expulsión inmediata del proyecto y pueden ser reportadas a las autoridades pertinentes.

**Mandatory Restrictions / Restricciones Obligatorias:**
- **Never publicly disclose vulnerabilities before official resolution and coordinated disclosure.**
- **Never exploit vulnerabilities in any environment, including testing, without explicit written permission.**
- **Never share sensitive information, PoC, or exploit details outside the official reporting channel.**
- **Never conduct destructive, malicious, or denial-of-service tests.**
- **Never attempt unauthorized access, privilege escalation, or data exfiltration.**
- **Never use automated tools or scripts against production systems without prior approval.**
- **Never retain, copy, or distribute confidential project data.**

- **Nunca divulgar públicamente vulnerabilidades antes de la resolución oficial y divulgación coordinada.**
- **Nunca explotar vulnerabilidades en ningún entorno, incluido pruebas, sin permiso escrito explícito.**
- **Nunca compartir información sensible, PoC o detalles de exploits fuera del canal oficial de reporte.**
- **Nunca realizar pruebas destructivas, maliciosas o de denegación de servicio.**
- **Nunca intentar acceso no autorizado, escalado de privilegios o exfiltración de datos.**
- **Nunca usar herramientas o scripts automatizados contra sistemas de producción sin aprobación previa.**
- **Nunca retener, copiar o distribuir datos confidenciales del proyecto.**

**Advanced Best Practices / Buenas Prácticas Avanzadas:**
- Maintain all dependencies, libraries, and environments at the latest patch level.
- Use encrypted and private channels for all security communications.
- Review version history, changelogs, and known issues before reporting.
- Provide clear, concise, and actionable information in all communications.
- Participate in regular security training and awareness programs.
- Perform periodic security audits and code reviews.
- Use multi-factor authentication and strong password policies.
- Report suspicious activity or policy violations immediately.

- Mantén todas las dependencias, librerías y entornos en el último nivel de parche.
- Utiliza canales cifrados y privados para todas las comunicaciones de seguridad.
- Revisa el historial de versiones, changelogs y problemas conocidos antes de reportar.
- Proporciona información clara, concisa y accionable en todas las comunicaciones.
- Participa en programas regulares de formación y concienciación en seguridad.
- Realiza auditorías de seguridad y revisiones de código periódicas.
- Utiliza autenticación multifactor y políticas de contraseñas robustas.
- Reporta inmediatamente cualquier actividad sospechosa o violación de políticas.

---

## 🛡️ Security Commitment / Compromiso de Seguridad

We are fully committed to:
- Rigorous review and resolution of all vulnerabilities.
- Absolute transparency with the community, within the limits of responsible disclosure.
- Protection of reporter privacy and confidentiality.
- Continuous improvement of security policies, processes, and technologies.
- Enforcement of all restrictions and best practices without exception.

Estamos plenamente comprometidos a:
- Revisar y resolver todas las vulnerabilidades de forma rigurosa.
- Mantener absoluta transparencia con la comunidad, dentro de los límites de la divulgación responsable.
- Proteger la privacidad y confidencialidad de los reporteros.
- Mejorar continuamente las políticas, procesos y tecnologías de seguridad.
- Aplicar todas las restricciones y buenas prácticas sin excepción.

---

Thank you for your strict adherence to our security policy and for helping protect the integrity, safety, and quality of our project. Your responsible collaboration is essential for the security of all users. For any questions, contact exclusively by email.

Gracias por cumplir estrictamente nuestra política de seguridad y por ayudar a proteger la integridad, seguridad y calidad de nuestro proyecto. Tu colaboración responsable es esencial para la seguridad de todos los usuarios. Para cualquier consulta, contacta exclusivamente por correo electrónico.

