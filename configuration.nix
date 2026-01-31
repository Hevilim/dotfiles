{ config, lib, pkgs, ... }:

{
  imports =
    [ # Include the results of the hardware scan.
      ./hardware-configuration.nix
      # Include the necessary packages and configuration Apple Silicon support.
      ./apple-silicon-support
    ];

  boot.loader.grub = {
    enable = true;
    device = "nodev";
  };
  boot.loader.efi.canTouchEfiVariables = false;
  
  boot = {
    kernelParams = [
      "zswap.enabled=1"
      "zswap.compressor=zstd"
      "zswap.zpool=zsmalloc"
      "zswap.max_pool_percent=50"
    ];
  };
  swapDevices = [ { 
    device = "/swapfile"; size = 8192; 
  } ];

  hardware.asahi.enable = true;
  hardware.asahi.setupAsahiSound = true;

  networking.hostName = "nixos";
  services.tlp.enable = true;

  hardware.bluetooth = {
	enable = true;
    powerOnBoot = true;
  };

  programs.ssh.startAgent = true;

  networking.wireless.iwd = {
    enable = true;
    settings.General.EnableNetworkingConfiguration = true;
  };

  networking.networkmanager = {
    enable = true;
    wifi.backend = "iwd";
  };
 
  time.timeZone = "Asia/Almaty";

  hardware.apple.touchBar = {
    enable = true;
    package = pkgs.tiny-dfr;
    settings = {
      MediaLayerDefault = true;
      EnablePixelShift = true;
    };
  };

  boot.binfmt.emulatedSystems = [ "x86_64-linux" ];

  virtualisation.docker = {
	enable = true;
	enableOnBoot = true;
  };

  # Enable CUPS to print documents.
  # services.printing.enable = true;

  services.pipewire = {
    enable = true;
    pulse.enable = true;
  };

  users.users.karim = {
    isNormalUser = true;
    extraGroups = [ "wheel" "docker" ];
    packages = with pkgs; [
      tree
    ];
  };

  fonts.packages = with pkgs; [
    nerd-fonts.jetbrains-mono
    nerd-fonts.dejavu-sans-mono
    noto-fonts
  ];

  services.displayManager.sddm = {
    enable = true;
    wayland.enable = true;
    settings = {
      General = {
        GreeterEnvironment = "QT_SCREEN_SCALE_FACTORS=1.8";
      };
      Theme = {
        CursorTheme = "Bibata-Modern-Classic"; 
        CursorSize = 38;
      }; 
    };
  };

  programs.vim = {
    enable = true;
    defaultEditor = true;
    package = pkgs.vim.customize {
      name = "vim";
      # Install plugins for example for syntax highlighting of nix files
      vimrcConfig.packages.myplugins = with pkgs.vimPlugins; {
        start = [ catppuccin-vim ];
        opt = [];
      };
      vimrcConfig.customRC = ''
        set nocompatible
        set backspace=indent,eol,start
        set termguicolors
        colorscheme catppuccin_mocha
        syntax on
        set number
        set relativenumber
        set tabstop=4 
        set mouse=a
        autocmd FileType nix setlocal tabstop=2
      '';
    };
  };

  programs.hyprland = {
    enable = true;
    xwayland.enable = true;
  };
  programs.firefox.enable = true;
  programs.waybar.enable = true;
  programs.light.enable = true;

  nixpkgs.config.allowUnfree = true;

  # a b c d e f g h i j k l m n o p q r s t u v w x y z
  environment.systemPackages = with pkgs; [
    #sommelier
    bibata-cursors
    bluez
    brightnessctl
    cliphist
    conda
    curl
    distrobox
    fastfetch
    fex
    file
    gcc
    git
    grim
    htop
    hyprpaper
    inkscape
    jdk
    kdePackages.kdenlive
    kitty
    kittysay
    muvm
    nwg-look
    obsidian
    python3
    qemu
    qemu-utils
    slurp
    stow
    telegram-desktop
    vesktop
    vscodium
    wev
    wget
    wl-clip-persist
    wl-clipboard
    wlogout
    wofi
    xorg.xhost
    yandex-music
		pavucontrol
		walker
  ];

  # Some programs need SUID wrappers, can be configured further or are
  # started in user sessions.
  # programs.mtr.enable = true;
  # programs.gnupg.agent = {
  #   enable = true;
  #   enableSSHSupport = true;
  # };

  # List services that you want to enable:

  # Enable the OpenSSH daemon.
  # services.openssh.enable = true;

  system.stateVersion = "25.11";

}

