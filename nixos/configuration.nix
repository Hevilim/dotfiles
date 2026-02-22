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
		font = "${pkgs.dejavu_fonts}/share/fonts/truetype/DejaVuSansMono.ttf";
		fontSize = 32;
	};
	boot.loader.efi.canTouchEfiVariables = false;

	boot.plymouth = {
		enable = true;
		theme = "tribar";
	};

	boot.consoleLogLevel = 0;
	boot.initrd.verbose = false;

	boot = {
		kernelParams = [
			"quiet"
			"splash"
			"udev.log_level=0"
			"rd.systemd.show_status=false"
			"rd.udev.log_level=0"
			"systemd.show_status=false"
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
	hardware.graphics.enable = true;
	#hardware.asahi.enable = true;
	#hardware.asahi.setupAsahiSound = true;
	services.hardware.bolt.enable = true;

	networking.hostName = "nixos";
	services.tlp.enable = true;

	i18n.defaultLocale = "en_US.UTF-8";
	console = {
		font = "Lat2-Terminus16";
		keyMap = "us";
	};

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

	virtualisation.libvirtd.enable = true;
	programs.virt-manager.enable = true;
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

	xdg.portal = {
		enable = true;
		extraPortals = with pkgs; [
			xdg-desktop-portal-hyprland
			xdg-desktop-portal-gtk
		];

		config.common.default = "*";
		config.hyprland.default = [ "hyprland" "gtk" ];
	};

	users.users.karim = {
		isNormalUser = true;
		extraGroups = [ "wheel" "docker" "networkmanager" "libvirtd" ];
		packages = with pkgs; [
			tree
		];
	};


	nix.settings.experimental-features = [ "nix-command" "flakes" ];

	fonts.packages = with pkgs; [
		nerd-fonts.jetbrains-mono
		nerd-fonts.dejavu-sans-mono
		source-code-pro
		noto-fonts
		pixel-code
	];

	services.displayManager.sddm = {
		enable = true;
		wayland.enable = true;
		theme = "${pkgs.sddm-astronaut.override { embeddedTheme = "hyprland_kath"; }}/share/sddm/themes/sddm-astronaut-theme";
		extraPackages = with pkgs; [
			(sddm-astronaut.override { embeddedTheme = "hyprland_kath"; })
			kdePackages.qtsvg
			kdePackages.qtmultimedia
			kdePackages.qtvirtualkeyboard
		];
		settings = {
			General = {
				GreeterEnvironment = "QT_SCREEN_SCALE_FACTORS=2";
			};
			Theme = {
				CursorTheme = "Adwaita";
				CursorSize = 48;
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
			start = [ 
				catppuccin-vim 
				gruvbox
			];
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
			set tabstop=2 
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
	services.hypridle.enable = true;
	programs.hyprlock.enable = true;

	nixpkgs.config = {
		allowUnfree = true;
		allowUnsupportedSystem = true;
	};

	# a b c d e f g h i j k l m n o p q r s t u v w x y z
	environment.systemPackages = with pkgs; [
		asahi-audio
		erofs-utils
		cisco-packet-tracer_9
		squashfuse
		squashfsTools
		catppuccin
		catppuccin-kde
		(catppuccin-gtk.override { variant = "mocha"; })
		swww
		wayland-logout
		nmgui
		kdePackages.plasma-nm
		bluez
		brightnessctl
		cliphist
		conda
		curl
		distrobox
		fastfetch
		fex
		file
		#gcc
		gcc14
		gdb
		git
		grim
		htop
		inkscape
		jdk
		kdePackages.kdenlive
		kitty
		kittysay
		muvm
		nwg-look
		obsidian
		obs-studio
		pavucontrol
		python3
		qemu
		qemu-utils
		#sommelier
		slurp
		stow
		telegram-desktop
		vesktop
		vscodium
		walker
		wev
		wget
		wl-clip-persist
		wl-clipboard
		wlogout
		wofi
		yandex-music
		linux-wallpaperengine
		unzip
		dracula-icon-theme
		hyprpicker
		nodejs
		indent
		blueman
		mako
		adwaita-icon-theme
		nemo
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
