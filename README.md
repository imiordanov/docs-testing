# Calculator Library 📚

A simple repository showcasing **automated documentation generation** with Python and C++. This project demonstrates how to set up **pdoc** and **Doxygen** to work together with GitHub Actions and Pages.

## 🎯 Documentation Showcase

This repository highlights:
- **Dual-language documentation** (Python + C++)
- **Automated builds** with GitHub Actions
- **Professional presentation** with a unified landing page
- **Rich visual diagrams** for C++ code relationships

## 📖 View Documentation

**[🔗 Live Documentation](https://imiordanov.github.io/docs-testing/)**

The documentation includes:
- **Python API** - Generated with pdoc from docstrings
- **C++ API** - Generated with Doxygen including UML diagrams

## 🔧 Documentation Architecture

### Tools Used
- **[pdoc](https://pdoc.dev/)** - Python documentation from docstrings
- **[Doxygen](https://doxygen.nl/)** - C++ documentation with diagrams
- **GitHub Actions** - Automated builds on every push
- **GitHub Pages** - Static hosting

### Project Structure
```
docs/
├── index.html           # Static landing page (version controlled)
├── python/              # Python docs (pdoc generated)
│   └── calculator.html
└── cpp/                 # C++ docs (Doxygen generated)
    └── index.html
```

### How It Works

1. **Static Landing Page**: The main static file `docs/index.html` provides navigation between language-specific docs

2. **Python Documentation**: Built with pdoc to `docs/python/`
   ```bash
   uv run pdoc calculator.py -o docs/python
   ```

3. **C++ Documentation**: Built with Doxygen to `docs/cpp/` using the dedicated GitHub Action
   ```yaml
   - uses: mattnotmitt/doxygen-action@v1
     with:
       doxyfile-path: './Doxyfile'
   ```

4. **GitHub Action**: Coordinates both tools and deploys to Pages
   - Preserves the static landing page
   - Builds both documentation sets
   - Uploads everything as a single Pages artifact

