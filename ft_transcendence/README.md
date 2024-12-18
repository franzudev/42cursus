<div id="top"></div>



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]

[//]: # ([![LinkedIn][linkedin-shield]][linkedin-url])



<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/franzudev/ft_transcendence">
    <img src="images/logo.png" alt="Logo" width="80" height="80">
  </a>

<h3 align="center">ft_trascendence</h3>

  <p align="center">
    Last mandatory project of the 42 cursus
    <br />
    <a href="https://github.com/franzudev/ft_transcendence"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/franzudev/ft_transcendence">View Demo</a>
    ·
    <a href="https://github.com/franzudev/ft_transcendence/issues">Report Bug</a>
    ·
    <a href="https://github.com/franzudev/ft_transcendence/issues">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#apis">APIs</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->

## About The Project

[![Product Name Screen Shot][product-screenshot]](https://example.com)

Here's a blank template to get started: To avoid retyping too much info. Do a search and replace with your text editor
for the
following: `franzudev`, `ft_transcendence`, `twitter_handle`, `linkedin_username`, `email_client`, `email`, `project_title`, `project_description`

<p align="right">(<a href="#top">back to top</a>)</p>

### Built With

* [Nest.js](https://nestjs.com/)
* [Vue.js](https://vuejs.org/)
* [Docker](https://docker.com/)
* [PostgreSQL](https://postgresql.org/)

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- GETTING STARTED -->

## Getting Started

To get a local copy up and running follow these simple example steps.

### Prerequisites

This is an example of how to list things you need to use the software and how to install them.

* Docker Desktop
    * [Download Docker](https://www.docker.com/products/docker-desktop)
* pre-commit
  ```sh
  brew install pre-commit
  
  # Install the pre-commit-hook
  pre-commit install --hook-type commit-msg --hook-type pre-push
  
  ```
* nest-cli
  ```sh
  ### ONLY IN 42 ###
  mkdir ~/goinfre/.npm-global
  npm config set prefix '~/goinfre/.npm-global'
  echo 'export PATH=~/.npm-global/bin:$PATH' >> ~/.zshrc
  source ~/.zshrc
  ### ONLY IN 42 ###
  
  npm install -g @nestjs/cli
  ```

### Installation

1. Clone the repo
   ```sh
   git clone git@github.com:franzudev/ft_transcendence.git
   ```
2. Initialize git flow
   ```sh
   cd ft_transcendence

   git flow init <<EOF
   main
   develop
   feature/
   bugfix/
   release/
   hotfix/
   support/
   v
   ${PWD}/.git/hooks
   EOF
   ```
3. Start the development environment
   ```sh
   docker compose up --build
   ```

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->

## Usage

Use this space to show useful examples of how a project can be used. Additional screenshots, code examples and demos
work well in this space. You may also link to more resources.

_For more examples, please refer to the [Documentation](https://example.com)_

<p align="right">(<a href="#top">back to top</a>)</p>

## APIs

Api generation [Link](https://joolfe.github.io/postman-to-openapi/#install)_

<!-- ROADMAP -->

## Roadmap

- [ ] Feature 1
- [ ] Feature 2
- [ ] Feature 3
    - [ ] Nested Feature

See the [open issues](https://github.com/franzudev/ft_transcendence/issues) for a full list of proposed features (and
known issues).

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- CONTRIBUTING -->

## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any
contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also
simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- LICENSE -->

## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- CONTACT -->

## Contact

Your Name - [@twitter_handle](https://twitter.com/twitter_handle) - email@email_client.com

Project Link: [https://github.com/franzudev/ft_transcendence](https://github.com/franzudev/ft_transcendence)

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- ACKNOWLEDGMENTS -->

## Acknowledgments

* []()
* []()
* []()

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->

[contributors-shield]: https://img.shields.io/github/contributors/franzudev/ft_transcendence.svg?style=for-the-badge

[contributors-url]: https://github.com/franzudev/ft_transcendence/graphs/contributors

[forks-shield]: https://img.shields.io/github/forks/franzudev/ft_transcendence.svg?style=for-the-badge

[forks-url]: https://github.com/franzudev/ft_transcendence/network/members

[stars-shield]: https://img.shields.io/github/stars/franzudev/ft_transcendence.svg?style=for-the-badge

[stars-url]: https://github.com/franzudev/ft_transcendence/stargazers

[issues-shield]: https://img.shields.io/github/issues/franzudev/ft_transcendence.svg?style=for-the-badge

[issues-url]: https://github.com/franzudev/ft_transcendence/issues

[license-shield]: https://img.shields.io/github/license/franzudev/ft_transcendence.svg?style=for-the-badge

[license-url]: https://github.com/franzudev/ft_transcendence/blob/master/LICENSE.txt

[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555

[linkedin-url]: https://linkedin.com/in/linkedin_username

[product-screenshot]: images/screenshot.png
